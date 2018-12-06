class Test:
    def __init__(self):
        print("constructor")
        self.a = 10
        self.b = 20

    def setData(self,x,y):
        print('set self id',id(self))
        self.a = x
        self.b = y

    def show(self):
        print('show self id', id(self))
        print(self.a,self.b)


tt = Test()
tt.show()
tt.setData(30,40)
tt.show()

----------------------------------------------
class Test:
    def __init__(self):
        print("constructor")
        self.a = 10
        self.b = 20

    def setData(self,x,y):
        print('set self id',id(self))
        self.a = x
        self.b = y

    def show(self):
        print('show self id', id(self))
        print(self.a,self.b)


tt = Test()
tt.show()
tt.setData(30,40)
tt.show()

ss = Test()
print('ss id: ',id(ss))
ss.setData(30,40)
ss.show()

#동일한 클래스에서 여러개의 객체가 발생한 경우
# 멤버 데이터는 별도(heap)로 생성되지만 멤버함수(코드)는 공유한다.
# 그런데 어떻게 각각의 객체의 영역에 값을 W/R 할 수 있는가 -> self 로 제어된다.
-----------------------------------------------------

class Test:
    #파이썬에는 오버로딩이 없다.
    def __init__(self,x=0,y=0): #생성자에도 인자를 보낼 수 있다.( 기본값을 지정해놓으면 인자없이 호출가능)
        print("constructor")
        self.a = x
        self.b = y
    def __del__(self):  ##객체 소멸전에 호출
        print("destructor call")
    def setData(self,x,y):
        print('set self id',id(self))
        self.a = x
        self.b = y

    def show(self):
        print('show self id', id(self))
        print(self.a,self.b)

def fn():
    obj = Test(10,20)
    obj.show()
    return obj

#fn()
rst = fn()
print("hello")
rst.setData(100,200)
rst.show()

# obj = Test(10,20) #obj.__init__(obj,10,20)
# obj.show()
# my=obj
# obj = 'abc'
# print("hello")
# my.show()
#
# obj1 = Test()
# obj1.show()
#

-------------------------------------------------------
'''
data=[]
def inputData():
    while True:
        name = input('이름:')
        kor = int(input('국어:'))
        eng = int(input('영어:'))
        data.append((name,kor,eng))
        yn=input('계속입력(y/n)')
        if yn == 'n':
            break;

def outputData():
    for n,k,e in data:
        print("%s %d %d"%(n,k,e))

inputData()
outputData()
'''


class Grade:
    def __init__(self):
        self.data = []

    def inputData(self):
        while True:
            name = input('이름:')
            kor = int(input('국어:'))
            eng = int(input('영어:'))
            self.data.append((name, kor, eng))
            yn = input('계속입력(y/n)')
            if yn == 'n':
                break;

    def outputData(self):
        for n, k, e in self.data:
            print("%s %d %d" % (n, k, e))

grade = Grade()
grade.inputData()
grade.outputData()
-------------------------------------------------------------

class People:
    def __init__(self,name,age):
        self.name= name
        self.age=age

    def setName(self,name):
        self.name = name

class Student(People):
    def __init__(self,name,age,stdNum):
        super().__init__(name,age)
        self.stdNum=stdNum

std= Student('홍길동',20,20181205) #std.__init__(std,'홍길동',20,20181205)
std.setName('이순신')
print(std.name,std.age,std.stdNum)
----------------------------------------------------------
class Pet:              # 추상클래스
    def Sleep(self):
        print('zzz')
    def Eat(self):      # 추상함수
        #print('???')
        pass

class Dog(Pet):
    def Speak(self):
        print("bow wow")
    def Eat(self):      # 재정의 (override)
        print("bone")

dog = Dog()
dog.Eat()
dog.Sleep()
dog.Speak()
------------------------------------------------------
class Test:
    def __init__(self,x=0,y=0):
        self.a = x
        self.b = y
    def setData(self,x,y):
        self.a = x
        self.b = y

    def show(self):
        print(self.a,self.b)

tt = Test()
print(tt)
--------------------------------------------------------


# a = 10
# b = 0 #0으로 나누면 무한대이기 때문에 주금ㅠ
# rst = a/b
# print(rst)


# 프로그램 상 자주 발생하는 에러는 파이썬이 자동으로 해당 예외 클래스 객체를 생성한다.
'''
try:
    a=10
    b=0
    rst = a/b
    print(rst)
except Exception as err:
    print("에러:",err)


try:
    a = int(input("정수입력:"))
    rst = a +10
    print(rst)
except Exception as err:
    print("에러 :", err)

print("hello")
'''

def fn(a):
    if a==3:
        raise Exception('3입력안됨')    #강제로 예외 발생
    return a

try:
    rst = fn(3)
    print(rst)
except Exception as err:
    print("에러:",err)
  
 --------------------------------------------------------------------
 def hap(a,b):
    return a+b

def gop(a,b):
    return a*b

print("mymodule...", __name__)

------------------------------------------
import mymodule   #.py .pyc .pyd 확장자만 가능
#python -m py_compile mymodule.py 하면 컴파일 파일이 생성됨(.pyc)

import sys
print(sys.path)

rst = mymodule.hap(10,20)
print(rst)

rst=mymodule.gop(10,20)
print(rst)


import statistics as st # as로 축약 가능
st.Decimal


from mymodule import hap,gop    # mymodule에서 hap,gop을 import해서 쓰겠다.
hap(10,20)  # 그냥 쓸 수 있음
-----------------------------------------------------------
import mymodule

#mymodule이 한번 컴파일 되고 실행됨

def main():
    print("usemodule2",__name__)
    rst = mymodule.hap(10,20)
    print(rst)

    rst=mymodule.gop(10,20)
    print(rst)

if __name__ == '__main__':
    main()

# 다른 데서 이 파일을 import했을 경우
#  __name__이 __main__이 아니므로 main()이 실행되지 않는다.


------------------------------------------------------------------
import mymath.circle as c
#import mymath.danwi as d
from mymath.danwi import *

rst = c.circleArea(3)
print(rst)
#rst = d.cmToInch(10)
rst = cmToInch(10)
print(rst)


---------------------------------------------------
from mymath import circle, danwi

rst=circle.circleArea(10)
print(rst)
rst = danwi.cmToInch(10)
print(rst)

--------------------------------------
<file>
def fileWrite():
    fp = open('test.txt','w')
    print(fp.tell())    #커서 위치 어디있는지 알려줌
    fp.write('korea')
    fp.write('hello')
    fp.seek(3)          #커서 위치 바꿈
    fp.write('hi')
    fp.close()

def fileRead():
    fp = open('test.txt','r')
    print(fp.tell())
    rd = fp.read(3)     #3byte만 읽어오겠다.
    print(fp.tell())
    fp.close()
    print(rd)

fileWrite()
fileRead()

def fileWrite1():
    fp = open('test.txt','w')
    fp.write('asfbdfbhdfh')
    fp.close()

def fileRead1():
    fp = open('test.txt','r')
    while True:
        rd = fp.read(3)
        #if rd =='':
        if not rd:
            break
        print(rd)

    fp.close()

fileWrite1()
fileRead1()

def fileWrite2():
    fp = open('test.txt','w')
    fp.write('asf\nbdf\nbhd\nfh')
    fp.close()

def fileRead2():
    fp = open('test.txt','r')
    rd = fp.readlines()     #라인단위로 읽어서 리스트에 담아줌
    print(rd)
    rd = [ n for n in rd]
    # for rd in fp:   # 라인 단위로 끝까지 읽음
    #     print(rd)
    # rd = fp.readline()    #한 라인을 읽어옴
    # print(rd)
    # rd=fp.readline()
    # print(rd)
    fp.close()


fileWrite2()
fileRead2()
 ---------------------------------------------------------------
 1. births.txt 를 읽어 다음과 같이 출력하시요
년도:
남아수:
여아수:
-------------
....

2. 남아수 출생이 가장 많은 년도와 출생수를 구하시요
3. 여아수 총합과 평균과 가장큰값을 구하시요
4. 2000년 이후 데이터(년도, 남아수, 여아수) 를 출력하시요

5. 남아 출생수가 가장 많은 년도와 남아수 top5 를 구하시요

6. 여아출생수가 1300000 이상인 년도와 여아수를 출력하시요

7. 남아 여아 출생 표준편차를 구하시요

----------------------------------------------------------
import statistics as st
data =[]
def inputData():
    while True:
        name = input('이름:')
        kor = int( input('국어:') )
        eng = int( input('영어:') )
        data.append( (name,kor,eng) )
        yn = input('계속입력(y/n):')
        if yn=='n':
            break

def title():
    print("==" * 20)
    print("{0:10}{1:10}{2:10}{3:10}{4:10}".format("이름",
                                                  '국어', '영어', '총합', '평균'))
    print("==" * 20)

def statisticsFn():
    ktot = sum([n[1] for n in data])
    etot = sum([n[2] for n in data])
    kmean = st.mean([n[1] for n in data])
    emean = st.mean([n[2] for n in data])
    kmax = max(data, key=lambda n: n[1])[1]
    emax = max(data, key=lambda n: n[2])[2]
    print("국어총합", ktot, "영어총합", etot)
    print("국어평균", kmean, "영어평균", emean)
    print("국어max", kmax, "영어max", emax)

def outputData():
    title()
    for dt in data:
        d =[n for n in dt if type(n)==int ]
        tot = sum( d ) #dt[1]+dt[2]
        avg = st.mean(d)#tot/2
        print( "{0:10}{1:10}{2:10}".format( *dt ),
               "{0:9}{1:10}".format(tot,avg) )
    statisticsFn()

def searchData():
    sName = input('검색할 이름을 입력:')
    # sData = [n for n in data if sName in n[0]]
    sData = filter(lambda n:sName in n[0], data)
    title()
    for dt in sData:
        d =[n for n in dt if type(n)==int ]
        tot = sum( d ); avg = st.mean(d)
        print( "{0:10}{1:10}{2:10}".format( *dt ),
               "{0:9}{1:10}".format(tot,avg) )

def main():
    menu={1:inputData,2:outputData,3:searchData,4:exit}
    while True:
        print('성적정보','-'*10,
              '1.입력','2.출력','3.검색','4.종료',sep='\n')
        nSel = int(input('메뉴를선택하세요:') )
        menu[nSel]()

main()




