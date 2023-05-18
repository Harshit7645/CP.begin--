#include <iostream>
#include<fstream>
#include <cassert>
#include <cstdlib>
#include <ctime>

#define HIT 1
#define MISS 0
#define READ 0
#define WRITE 1
#define PageHitDelay 50
#define PageMissDelay 600

#define DEBUG 1

using namespace std;
int LRUCtr=0;

ofstream MTF("dram_tracefile.txt");

class Bank {
	int Address;
	int RowBufferAddess;
	int PageSize, NumRowPerBank, NumColumnPerRow;
	int PageHit=0, PageMiss=0;
	int ReadCtr=0, WriteCtr=0;
	public: 
	Bank(){}
	void init(int RowPerBank, int ColPerRow){
		NumRowPerBank=RowPerBank;
		NumColumnPerRow=ColPerRow;
		PageSize=NumColumnPerRow;
	}
	int Access(int Addr26, bool RW){
		int Addr18=Addr26 %(NumRowPerBank*NumColumnPerRow);
		int Row=Addr18/NumColumnPerRow;
		if (RW) WriteCtr++; else ReadCtr++;
		if (RowBufferAddess==Row) {
			PageHit++; return PageHitDelay;
		}
		PageMiss++; RowBufferAddess=Row; 
		return PageMissDelay;		
	}
	int getNumPageHits(){return PageHit;}
	int getNumPageMisses(){return PageMiss;}
	int getNumWrite(){return WriteCtr;}
	int getNumRead(){return ReadCtr;}
};

class Memory{
	int NumChannel, NumRankPerChannel, NumBankPerRank;
	int NumRowPerBank, NumColumnPerRow;

	int SizeOfMemInByte, PageSize, TotalNumBank;
	Bank *B;
	public:
	Memory(int c, int r, int b, int row, int col){
		NumChannel=c; NumRankPerChannel=r; NumBankPerRank=b; NumRowPerBank=row; NumColumnPerRow=col;
		SizeOfMemInByte=NumChannel*NumRankPerChannel*NumBankPerRank*NumRowPerBank*NumColumnPerRow;
		PageSize=NumColumnPerRow;
		TotalNumBank=NumChannel*NumRankPerChannel*NumBankPerRank;
		B= new Bank[TotalNumBank];
		for(int i=0;i<TotalNumBank;i++) {
			B[i].init(NumRowPerBank,NumColumnPerRow);
		}
	}	
	void Access(int Address, bool RW){
		int ch, rnk, bnk;
		//Assume address is 32 bit, but will use only 26 bits as we assume memory is 64MB
		if ( Address<0) cout<<Address<<" "<<RW<<"\n";
		int Addr26=Address%(1<<26);
		bnk =  Addr26 / (NumRowPerBank*NumColumnPerRow);
		B[bnk].Access(Addr26, RW);
	}	  
	int readblock(int Address){ Access(Address,0); MTF<<std::hex<<Address<<std::dec<<" R\n"; return 1;}
	int writeblock(int Address){Access(Address,1); MTF<<std::hex<<Address<<std::dec<<" W\n"; return 1;}
	void PrintStat(){
		int TotalPageHit=0, TotalPageMiss=0;
		int TotalWrite=0, TotalRead=0;
		for(int i=0;i<TotalNumBank;i++){
			TotalPageHit +=B[i].getNumPageHits();
			TotalPageMiss+=B[i].getNumPageMisses();
			TotalWrite += B[i].getNumWrite();
			TotalRead += B[i].getNumRead();
		}
		cout<<"\n\nMemory Statistics:\nTotalPageHit="<<TotalPageHit<<" TotalPageMiss="<<TotalPageMiss;
		cout<<"\nTotalRead="<<TotalRead<<" TotalWrite="<<TotalWrite<<"\n";
	}
};

Memory M(2,8,16,256,1024); //Size of this memory is 64MB=2*8*16*256*1024B
			   //Number of Memory Banks = 2*8*16 =256
			   //Each Bank Size is 256*1024=256KB

class Cache {
	private:
		int set, asso, LS;
		int hit_counter,miss_counter;
		int **TAG, **LRU;
		bool **Dirty;	
	public:
		int get_hit(void){return hit_counter;}
		int get_miss(void){return miss_counter;}
		Cache(){}
		void CacheInit( int sets, int associativity, int LineSize ) {
			int i, j;
			TAG = new int*[sets];
			LRU = new int*[sets];
			Dirty = new bool*[sets];
			for(i = 0; i < sets; i++){
				TAG[i] = new int [associativity];
				LRU[i] = new int [associativity];
				Dirty[i] = new bool [associativity];

			}
			/* Initialize tag to be -1 */
			for(i=0;i<sets;i++)
				for(j=0;j<associativity;j++) TAG[i][j]=0;
			/*cout << TAG[5][3] << endl;*/
			asso = associativity; set = sets; LS = LineSize;
			hit_counter=miss_counter=0;
		}
		~Cache(void){
			delete[] TAG;
		}
		int Access(unsigned int Address, bool RW) {
			int i, lru_index;
			int offset = Address % LS;
			int index = (Address/LS) % set;
			int Tag = (Address/LS)/set;
			/*if hit*/
			for(i = 0; i < asso; i++) //In real system, tag matching happens in parallel
				if( TAG[index][i] == Tag) {
					hit_counter++;
					LRU[index][i]=LRUCtr++;
					if (RW==WRITE) Dirty[index][i]=1;			
					return HIT;
				}
			miss_counter++;
			/*miss*/
			lru_index =0; // least recently used policy for replacement
			for(i = 1; i < asso; i++){
				if(LRU[index][i]<LRU[index][lru_index]) lru_index=i;		
			}
			M.readblock(Address); //Read Data Block from memory
			if (Dirty[index][lru_index]) {
				int OTag=TAG[index][lru_index]; //Writeback the Data to memory
				if (OTag>0) 
					M.writeblock((OTag*LS*set+index*LS));
				//if (DEBUG) cout<<"\nWriteHappens..\n";
			}
			TAG[index][lru_index] = Tag;

			return MISS;
		} 
};



int main()
{
	int hit;
	unsigned int Address;
	int j, CPUCycle, i =0;
	bool RW;
	int MaxAddress=1<<30;


	Cache L; 
	//ofstream TF("tracefile.txt");

	L.CacheInit(128, 4, 64);
	srand(time(NULL));
	Address = rand()%MaxAddress;
	for(CPUCycle = 0; CPUCycle < 25000; CPUCycle=CPUCycle+4) {
		if ((rand()%100) <20)
			Address = rand()%MaxAddress; //20% time it jump to new address
		else Address = Address+4; // 80% time it goes to next word
		if ((rand()%100)<20) RW=WRITE; else RW=READ;
		hit = L.Access(Address,RW);
		//TF<<CPUCycle<<" "<<std::hex<<Address<<" "<<std::dec<<RW<<endl;
	}/*end for loop*/
	cout<<"\nCache Statistics\n L: hit "<<L.get_hit()<<" miss "<<L.get_miss();
	M.PrintStat();
	cout<<"\n\nMy work is done\n\n";
	return 0;
}



