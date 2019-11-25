import pandas as pd
import sys
df = pd.read_csv(sys.argv[1], encoding='big5')
# print(df)
# df.info()
df1 = df[(df['商品代號'] == 'TX     ')]
# print(df1)
df2 = df1[df1['成交時間'].between(84500,134500)]
df2 = df2[df2['成交價格'] > 0]
df2.reset_index(drop=True, inplace=True)
# print(df2)
df2 = df2[(df2['到期月份(週別)'] == df2.loc[0,'到期月份(週別)'])]
# df2 = df2[(df2['到期月份(週別)'] == 201909)]
# print(df2['成交時間'])
open_price = int(df2.loc[0,'成交價格'])
close_price = int(df2.loc[len(df2)-1,'成交價格'])
high_price = int(df2.loc[df2['成交價格'].idxmax(),'成交價格'])
low_price = int(df2.loc[df2['成交價格'].idxmin(),'成交價格'])

print(open_price,high_price,low_price,close_price)