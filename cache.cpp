#include <iostream>
#include<fstream>
#include <cassert>
#include <cstdlib>
#include <ctime>

#define HIT 1
#define MISS 0
#define READ 0
#define WRITE 1

using namespace std;
int LRUCtr=0;

class Memory{
	public: 
	  int readblock(int Address){return 1;}
	  int writeblock(int Address){return 1;}
};

Memory M;

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
				for(j=0;j<associativity;j++) TAG[i][j]=-1;
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
			if (Dirty[lru_index][i]) {
				int OTag=TAG[index][lru_index]; //Writeback the Data to memory
				M.writeblock((OTag<<set+index)<<LS);
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
	ofstream TF("tracefile.txt");

	L.CacheInit(128, 4, 64);
	srand(time(NULL));
	Address = rand()%MaxAddress;
	for(CPUCycle = 0; CPUCycle < 5000; CPUCycle=CPUCycle+4) {
		if ((rand()%100) <20)
			Address = rand()%MaxAddress; //20% time it jump to new address
		else Address = Address+4; // 80% time it goes to next word
		if ((rand()%100)<20) RW=WRITE; else RW=READ;
		hit = L.Access(Address,RW);
		TF<<CPUCycle<<" "<<std::hex<<Address<<" "<<std::dec<<RW<<endl;
	}/*end for loop*/
	cout<<"\nL: hit "<<L.get_hit()<<" miss "<<L.get_miss();
	cout<<"\n\nMy work is done\n\n";
	return 0;
}



