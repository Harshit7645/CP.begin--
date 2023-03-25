import mysql.connector

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  password="harshit*123"
)

print(mydb)