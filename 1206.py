import pandas as pd
import numpy as np

data1 = [10,20,30,40]
data2 = {'aa':10,'bb':20,'cc':30}
sr = pd.Series(data1,dtype=np.int32,index=['a','b','c','d'])
sr1 = pd.Series(data2)
print(sr)
print(type(sr))
print(sr1)

----------------------------------------------
#1차원 데이터 관리
import pandas as pd

sr = pd.Series([10,20,30,40,50],index=['aa','bb','cc','dd','ee'])

print(sr)
print("-"*10)

#인덱스, 슬라이싱
print(sr[0])
print(sr['aa'])
print(sr[-1])
print(sr[1:4])
print(sr['bb':'dd'])

print(sr.loc['aa']) #부여된 인덱스를 주게 되어있음
print(sr.iloc[0])   #0 base index
print( sr[1] ) #부여된인덱스
print(sr.iloc[0]) #0 base 인덱스
print(sr.loc[1]) #부여된인덱스


sr.index=[1000,2000,3000,4000,5000]
print(sr)
print('-'*10)
#print(sr[0])    #인덱스가 숫자로 되어있으면 error남
print(sr[1000])  #부여된 인덱스로 접근!
print(sr.iloc[0])


#속성
#=======================
'''
print( sr.ndim )
print( sr.shape )
print( sr.size )
print( sr.dtype)
print( sr.index )
print( sr.values )
'''
#=======================

----------------------------------------------

import pandas as pd
import numpy as np

#1차원 데이터 관리
sr = pd.Series([10,20,30,40,50],index=['aa','bb','cc','dd','ee'])
print(sr.iloc[0:3])
print(sr.loc['bb':'dd'])
print(sr)
print("="*15)

#연산 ( 산술 연산자: 개별 데이터를 연산하게 된다. )
#print(sr+2)
#print(sr*2)
#print(sr+sr)

# 관계 연산자 : 개별 데이터 연산하여 True/False를 반환한다.
#print(sr>20)

# boolean indexing
print(sr[ [True,False,True,False,False] ])  #True 인 것만 불러옴
print(sr[sr>20])    # sr>20 은 f,f,t,t,t인 series이므로 불리언 인덱싱이 됨

#논리 연산자 : ==, | , &, 등
print( sr[(sr==20) | (sr==30) ])
print( sr[(sr>=20) & (sr<=40)])     #20<=sr<=40 (X)
print(~((sr==20) | (sr==30)) )


------------------------------------------------------------
import pandas as pd
import numpy as np

#세금 3.3을 제한 실수령액을 구하시오
sr = pd.Series([1000,2000,3000,4000,5000])

#print(sr*(1-0.033))

for n in sr:
    print(n)

for i,v in sr.items():
    print(i,v)

------------------------------------------------
import pandas as pd
import numpy as np

name=['홍길동','이순신','임꺽정','이이',
      '이황','정난정','김철수']
kor =[90,50,20,40,60,55,30]
sr = pd.Series(kor, index=name)
print(sr)
print("="*20)
#삭제
# sr = sr[ sr<= 50]
# sr = sr[ ~(sr== 50)]
# sr = sr[ sr!= 50]
# sr = sr.drop('홍길동')
sr.drop('홍길동', inplace=True )
print(sr)

'''
#수정
sr[1:4] = 2
sr[1:4] = sr[1:4]+2
sr[ sr>=50 ]= sr[ sr>=50 ] +2
print(sr)
'''
'''
#추가
sr['홍길동'] = 44 # sr[0] =44 #있으면수정
sr['김철수1'] =77 #없으면 추가
sr = sr.append( pd.Series([55,66,77],
    index=['김철수2','김철수3','김철수4']) )
print(sr)
'''



-------------------------------------------------

import pandas as pd
import numpy as np

name = ['홍길동','이순신','임꺽정','이이','이황','정난정','김철수']
kor = [90,50,20,40,60,55,30]
sr = pd.Series(kor,index=name)
print(sr)
print('='*20)
print('max:',sr.max())
print('min:',sr.min())
print("max값의 index: ",sr.idxmax())
print("min값의 index: ",sr.idxmin())
print('sum:', sr.sum())
print('50점 이상 sum: ',sr[sr>=30].sum())
print("평균값: ",sr.mean())
print("중간값 : ", sr.median()) #홀수개면 정렬했을 때 중간값, 짝수개면 중간 두개의 중간값
print("정렬했을 때 50%의 값:",sr.quantile(0.5))
print(sr.quantile([0.2,0.5,0.9]))
print("표준편차:",sr.std())

print('='*20)
print("오름차순 정렬")
print(sr.sort_values())
print('='*20)
print("내림차순 정렬")
print(sr.sort_values(ascending=False))
print('='*20)
print("인덱스 기준 정렬")
print(sr.sort_index())


print(sr.count())
print(sr[sr>20].count())

----------------------------------------------------------
import pandas as pd
import numpy as np

def fn(n,ar):
    return n+ar if n>=50 else n+3

name = ['홍길동','이순신','임꺽정','이이','이황','정난정','김철수']
kor = [90,50,20,40,60,55,30]
sr = pd.Series(kor,index=name)
print(sr)
print('='*15)
print(sr.apply(fn,args=(5,)))
#print(sr.apply(lambda n: n+2 if n>=50 else n+3))

sr.rename(index={'홍길동':'길동'},inplace=True)
print(sr)
-------------------------------------------------
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib
matplotlib.rcParams['font.family']='Malgun Gothic'
matplotlib.rcParams['axes.unicode_minus']=False

name = ['홍길동','이순신','임꺽정','이이','이황','정난정','김철수']
kor = [90,50,20,40,60,55,30]
sr = pd.Series(kor,index=name,name='국어점수')
print(sr.name)
print(sr)
#sr.plot()   #메모리 draw
#plt.show()  #메모리 --> video 메모리로 전송

#sr.plot(kind='bar',grid=True,figsize=(6,5),legend=True,title='1반학생점수',ylim=(0,100)) #bar형으로 나옴
#sr.plot(kind='hist')   #sr.hist(bins=5)
#sr.plot(kind='pie')
exp=(0.1,0,0,0,0,0,0)
sr.plot.pie(autopct='%.1f%%',shadow=True,explode=exp)
plt.xticks(rotation=45) #x축 글자를 45도 기울임
plt.show()

-----------------------------------------------------------

import pandas as pd
import numpy as np


name = ['홍길동','이순신','임꺽정','이이','이황','정난정','김철수']
kor = [90,50,20,40,60,55,30]
sr = pd.Series(kor,index=name,name='국어점수')
sr.to_csv('a.csv')
sr.to_csv('a.xlsx')

----------------------------------------------------
# os, sys, math, random, datetime

import os # 파일 및 디렉터리
import sys

'''
#os.mkdir('test')    #디렉터리 생성

print(os.getcwd()) #현재 경로

#os.rmdir('test') #디렉터리 삭제

#os.remove('test.txt') #파일 삭제

os.system('dir')
#os.system('notepad')    #command 명령어 실행 -> 메모장 실행됨
print(os.path.isdir('test')) #test라는 디렉터리가 있느냐 (True / False)
'''

'''
data = [10,20]
print(sys.getsizeof(data))
print(sys.getrefcount(data))
print(sys.path)
print(sys.argv) #명령행 인자


import math

print(math.pi)
print(math.fabs(-10))   #실수로 반환
print(abs(-10))         #정수로 반환
print(round(3.1345371,3))       #소수점 3자리까지만, 반올림
print(math.ceil(3.14))   #올림
print(math.floor(3.14) )        #버림

import datetime

dt = datetime.date(2011,12,4)
print(dt)
print(dt.year,dt.month,dt.day)
tm = datetime.time(10,11,13)
print(tm)
print(tm.hour,tm.minute,tm.second)
dttm = datetime.datetime(1999,4,10,3,10,13)
print(dttm)
cur = datetime.datetime.now()
print(cur)
print(cur.year,cur.month,cur.day,
      cur.hour,cur.minute,cur.second)
'''

import random

for _ in range(5):
    random.randint(1,5)

my = [n for n in range(1,11)]
print(random.sample(my,3))
random.shuffle(my)
print(my)



------------------------------------------

# coding: utf-8

# In[1]:


import pandas as pd
import numpy as np



# In[2]:


data1 = [[10,20],[30,40],[50,60]]
data2 = [(10,20),(30,40),(50,60)]
data3 = [ {'kor':10,'eng':20},
        {'kor':30,'eng':40},
        {'kor':50,'eng':60}]
data4 = {'kor':[10,30,50],'eng':[20,40,60]}



# In[3]:


df1 = pd.DataFrame(data1)
df1


# In[4]:


df2 = pd.DataFrame(data2)
df2


# In[5]:


df3 = pd.DataFrame(data3)
df3


# In[6]:


df4 = pd.DataFrame(data4)
df4


----------------------------------------

# coding: utf-8

# In[1]:


import pandas as pd
import numpy as np


# In[2]:


data1 = [[10,20],[30,40],[50,60]]
data2 = [(10,20),(30,40),(50,60)]
data3 = [ {'kor':10,'eng':20},
        {'kor':30,'eng':40},
        {'kor':50,'eng':60}]
data4 = {'kor':[10,30,50],'eng':[20,40,60]}


# In[5]:


df = pd.DataFrame(data1,index=['홍길동','이순신','임꺽정'],columns=['국어','영어'])
df


# In[6]:


df.ndim


# In[7]:


df.shape


# In[8]:


df.size


# In[9]:


df.index


# In[10]:


df.values


# In[11]:


df.columns


# In[12]:


df


# In[15]:


df['국어']   #0라고 주면 에러남
# Series로 반환됨

------------------------------------------

# coding: utf-8

# In[5]:


import pandas as pd
import numpy as np

data3 = [ {'kor':10,'eng':20,'math':30},
        {'kor':30,'eng':40,'math':40},
        {'kor':50,'eng':60,'math':60}]


# In[8]:


df = pd.DataFrame(data3)
df.index=['홍길동','임꺽정','이순신']
df


# In[9]:


df['eng']


# In[10]:


df.eng


# In[11]:


df[['eng','math']]


# In[12]:


df.loc['홍길동']


# In[13]:


df.iloc[0]


# In[17]:


# df.loc['홍길동':'이순신']
df.iloc[0:3]


# In[19]:


# df[0:3]
df['홍길동':'이순신']


# In[20]:


df.loc['임꺽정':]#임꺽정 이후에 끝까지


# In[21]:


df.loc['홍길동','kor']


# In[22]:


df.iloc[0,1]


# In[24]:


df.loc['이순신':,'kor':]


# In[25]:


df.loc['임꺽정':'이순신','kor':]


# In[27]:


df.loc['임꺽정':'이순신',['eng','math']]

