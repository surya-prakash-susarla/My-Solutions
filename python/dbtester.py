import MySQLdb

db = MySQLdb.connect ( host = "localhost" , user= "surya" , passwd= "surya" , db = "temp" )

cursor = db.cursor()

def db_show ( tables , cursor ):
    print "Displaying the names in the table \n"
    sql = """SELECT * FROM %s """%(tables)
    cursor.execute(sql)
    for row in cursor.fetchall():
        print row[0],"\t\t",row[1]

table_name  = raw_input("enter the name of the table to display\n")
db_show ( table_name , cursor)

name , value  = raw_input("enter the value to be stored in the table\n").split()

sql_stat = """INSERT INTO %s(name,id) VALUES('%s',%s)"""%(table_name, name, value)

cursor. execute(sql_stat)

db_show(table_name , cursor)

db.close()
