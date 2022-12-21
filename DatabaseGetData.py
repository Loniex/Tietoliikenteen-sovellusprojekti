import mysql.connector
import pandas as pd


db = mysql.connector.connect(host="172.20.241.9", 
                             user="dbaccess_ro", 
                             passwd="vsdjkvwselkvwe234wv234vsdfas", 
                             database="measurements", auth_plugin='mysql_native_password')
cursor = db.cursor()
cursor.execute("SELECT * FROM rawdata WHERE groupid=86")

response= cursor.fetchall()

df=pd.DataFrame(response)
df_csv=df.to_csv('Data1.csv')
