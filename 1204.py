
a = 1
while a<= 5:
    if a==3:
        break
    print("a= ",a)
    a+=1
else:                   # 정상적으로 false로 반복문 탈출인 경우에만 실행( 옵션 )
    print("else....")


-------------------------------------------------------------------

# for 변수 in 복합데이터타입(반복가능)

s = 'abc'
for n in s:
    print(n)

my = [10,20,30]
for n in my:
    print(n)

d = {'aa':10, 'bb':20, 'cc':30}
for n in d:
    print(n)

for n in d.keys():
    print(n)

for n in d.values():
    print(n)

for n in d.items():
    print(n)

for k,v in d.items():   # 언패킹이 일어난다.
    print(k,v)

-------------------------------------------------------------------
# range(시작값, 끝값, 증가치 )
# 시작값<= 리스트 < 끝값

r = range(1,5,1)
print(list(r))

r= range(1,5,2)
print(list(r))

r= range(1,11)      #증가치 생략 시 1씩 증가
print(list(r))

r= range(6)         #시작값 생략 시 0부터 시작
print(list(r))

for i in range(1,6):
    print(i)

-----------------------------------------------------------
# 리스트 내장 반복문

my = [n*10 for n in range(1,6)]
print(my)

my = [n*10 for n in range(1,6) if n%2==0]
print(my)

#세금 3.3 을 제한 실수령액을 구하시오
salary = [1000,2000,3000,4000,5000]
rSalary = [n*(1-0.033) for n in salary]
print(rSalary)
-------------------------------------------------------------

# 내장 딕셔너리
d = [('aa',10),('bb',20),('cc',30)]
my = {k:v for k,v in d}
print(my)

# 내장 set
s = {n for n in range(1,6)}
print(s)

# 내장 generator
g = ( n*10 for n in range(1,11))
print(g)
---------------------------------------------------------
import sys

my = [ n*10 for n in range(1,4)]
print(my)
print("my size", sys.getsizeof(my))

g = (n*10 for n in range(1,4))
print(g)
print("g size", sys.getsizeof(g))

# print(next(g))
# print(next(g))
# print(next(g))
# print(next(g))  # StopIteration 예외 발생

# for n in g:
#     print(n)

print(list(g))  #[next(g),next(g),next(g)]
# generator는 10,100,1000이여도 88이다
# generator는 그때 그때 연산한다....> next(g)

-----------------------------------------------------------


def fn():
    print('fn call')
    print('korea')

def hap(a,b):
    return a+b

fn()
fn()
fn()

i = hap(1,2)
print(i)
i = hap(10.2,20.3)
print(i)
i = hap('aaa','bbb')
print(i)
i= hap([1,2,3],[4,5,6])
print(i)
---------------------------------------------------------
# 함수의 리턴값이 두개 이상 올 수 있다.

def fn():
    return 10,20

rst = fn()  # 패킹이 발생해서 튜플로 나옴
print(rst)

a,b = fn()  # a=10 b=20 이 들어감
print(a,b)

def shape(r,h,w):
    return r**2*3.14,h*w

rst = shape(3,10,20)
print(rst)

def fn1(a,b):
    print(a,b)

fn1(10,20)
fn1(b=100,a=200)    #명시적 호출

def fn2(a=10,b=20,c=30):    #default 인자값을 가질 수 있다.
    print(a,b,c)

fn2()
fn2(100)
fn2(100,200)
fn2(100,200,300)
fn2(b=1000)

print(10,20,30,)    #print 함수의 구분자 기본값이 공백으로 들어가 있다.
print(10,20,30,sep='-')     #중간에 기본값으로 -이 들어가게됨
print('hello', end = ' ')  #print 함수의 마지막 인자값으로 개행문자가 기본값으로 들어가있다.
print('korea')

-------------------------------------------------------------
# 가변 인자

def fn(*args):
    print(args)

fn(10,20)
fn(10,20,30,40)

a = (10+2)*3        #연산자 우선 순위의 괄호
a = (10)    # 튜플 아님 ( 정수 )
print(type(a))
a = (10,)   # 튜플 ( 하나인 튜플 )
print(type(a))

fn((1,2))   #arg 1개 넘겨준것
fn( *(1,2) )        # * -> 언패킹 해줌
#==>fn(1,2)

def circles(*args):
    for r in args:
        print(r**2*3.14)

circles(1,2,3,4,5)

def fn1(**kwargs):      # 정의 되지 않은 인자
    print(kwargs)

fn1(aa=10,bb=20,cc=30)
fn1(name='홍길동',age=20)
d = {'name':'홍길동','age':30}     # 인자를 정의하지 않았기 때문에 에러가 남
#fn1(d)
fn1 (**d)   #딕셔너리를 언펙시키고 넘겨줌 fn(name='홍길동',age=30)


def fn2(a,*args):   # 가변인자는 반드시 뒤에 와야한다.
    print(a)
    print(args)


fn2(10,20,30,40)    # a=10 나머지는 가변인자

def fn3(*args,**kwargs):
    print(args)
    print(kwargs)

fn3(10,20,30)
fn3(aa=10,bb=20)
fn3(10,20,aa=100,bb=200)

a = 10
f = 3.14
c = 'abc'
s = "a={0}, f={1}, c={2}".format(a,f,c)
#s = "a={}, f={}, c={}".format(a,f,c) 순서는 생략 가능
s = "a={0:10}, f={1:10.2f}, c={2:>10}".format(a,f,c) #10칸, 10칸 + 소숫점 2자리 , 10캄
#s = "a={0:10}, f={1:10.2f}, c={2:10}".format(*(a,f,c)) # 튜플일 경우 언패킹해준다.
print(s)

d = {'name':'홍길동','age':30}
s = "이름 = {name},나이 = {age}".format(**d)
print(s)

s1 = '이름 : %(name)s 나이 :%(age)d'%d

---------------------------------------------------------------------------

data=[]
while True:
    name = input("이름:")
    kor = int( input("국어:") )
    eng = int( input("영어:") )
    # data.append( (name,kor,eng) )
    data.append({'name':name, 'kor':kor, 'eng':eng})
    yn = input("계속입력(y/n):")
    if yn=='n':
        break
print("=="*20)
print("{0:>8}{1:>8}{2:>8}".format('이름','국어','영어') )
print("=="*20)
for d in data:
    # print("{0:>10}{1:10}{2:10}".format(*d) )
    print("{name:>10}{kor:10}{eng:10}".format(**d))



------------------------------------------------------------------
#BUILT IN GLOALVARIABLE
# FUNCTION
#def print(..):
# ...
print(dir(__builtins__) )
g = 10

def fn():
    g = 100
    print("지역:",locals() )

fn()
print("g=", g)
print( globals() )
print(__file__)

---------------------------------------------------------
# 빌트인 심볼( 전역변수, 함수, 클래스)
# str="abc"
sum=0
g = 10
def fn():
    global g
    g = 100

fn()
print("g=", g)
n =100
s = str(n)
print(s)
print(sum( [10,20,30] ) )

--------------------------------------------------------
import sys
my = [10,20,30] #list([10,20,30])
print("my id", id(my) )
print( sys.getrefcount(my) -1)
# my1 = my #shallow copy(주소복사)
# my1 = [10,20,30]
my1 = my.copy() # deep copy
print("my1 id", id(my1) )
print( sys.getrefcount(my) -1 )
my1[0] = 100
print( my )


---------------------------------------------------------
def fn():
    my = [10,20,30]
    print(my)
    return my

rst = fn()
print(rst)




#파이썬 메모리관리 자동(RC)
my = [10,20,30]
my1 = my
my = 'abc'
print(my)

--------------------------------------------------------
#일급함수 : 함수에 대해 ,할당, 리턴, 아규먼트, 함수 안에 함수(데코레이터)


def fn():
    print("fn call")

print(globals())
my = fn         #코드 영역에 할당된 함수의 시작 주소
print(id(fn),id(my))
fn()    #fn의 주소로 이동해라
my()


def test():
    return fn
def test1(aa):
    aa()

my = test()     # my = fn
my()
test1(fn)

-------------------------------------------------------------
def fn1():
    print("fn1 call")


def fn2():
    print("fn2 call")


menu = {1:fn1, 2:fn2}
menu[1]()
menu[2]()

-----------------------------------------------------
#함수기반언어의 설계기법(유지보수가 용이하도록)
# 1. SRP
# 2. open closed 기법
# ( 기능확장에는 열려있고 기존코드수정에는 닫혀있도록한다 )

data1 =[10,60,70,40]
data2 =[(10,30),(70,50),(50,40)]
data3 =[{'kor':10,'eng':30},
        {'kor':70,'eng':50},
        {'kor':50,'eng':40}]
def mymax( dt):
    nMax = None
    for n in dt:
        # if nMax==None or n>nMax:
        # if nMax == None or n[0] > nMax[0]:
        # if nMax == None or n[1] > nMax[1]:
        if nMax == None or n['kor'] > nMax['kor']:
            nMax = n
    return nMax

mx = mymax(data3)
print(mx, mx['kor'])

# mx = mymax(data2)
# print(mx, mx[1])

# mx = mymax(data2)
# print(mx, mx[0])

# mx = mymax(data1)
# print(mx)










-----------------------------------------------------------------

data1 =[10,60,70,40]
data2 =[(10,30),(70,50),(50,40)]
data3 =[{'kor':10,'eng':30},
        {'kor':70,'eng':50},
        {'kor':50,'eng':40}]
def vFn( n ):
    return n
def tFn( n ):
    return n[0]
def dfn( v ):
    return v['kor']
def mymax( dt, key):
    nMax = None
    for n in dt:
        if nMax==None or key(n)>key(nMax):
            nMax = n
    return nMax
mx = mymax(data3, dfn)
print(mx)
# mx = mymax(data2, tFn)
# print(mx)
# mx = mymax(data1, vFn)
# print(mx)


-------------------------------------------------------------------
data1 =[10,60,70,40]
data2 =[(10,30),(70,50),(50,40)]
data3 =[{'kor':10,'eng':30},
        {'kor':70,'eng':50},
        {'kor':50,'eng':40}]
#dt =[10,60,70,40], key =lambda k:k
def mymax( dt, key=lambda k:k):
    nMax = None
    for n in dt:
        if nMax==None or key(n)>key(nMax):
            nMax = n
    return nMax

mx = mymax(data3, lambda k:k['kor'] )
print( mx)

# mx = mymax(data2, lambda k:k[1] )
# print( mx,mx[1])

# mx = mymax(data2, lambda k:k[0] )
# print( mx)

# mx = mymax(data1)
# print( mx)
# mx = mymax(data3, dfn)
# print(mx)

# def hap(a,b):
#     return a+b

# hap = lambda a,b : a+b
# rst = hap(10,20)
# print(rst )
-----------------------------------------------------------------
import statistics as st
data1 =[10,60,70,40]
data2 =[(10,30),(70,50),(50,40)]
data3 =[{'kor':10,'eng':30},
        {'kor':70,'eng':50},
        {'kor':50,'eng':40}]

print( st.mean(data1))
print( st.median(data1))
print(st.stdev(data1))
print( sum(data1) )
print( sum( [n[0] for n in data2] ) )

# m = map( lambda n:n+2, data1)
# print(m)
# print(list(m))

# def myfilter(key, dt):
#     return ( n for n in dt if key(n))
# f = myfilter(lambda k:k>20, data1)
# print(f)
# print(list(f))


# f = filter( lambda n:n>30, data1)
# print(f) #generator
# print(list(f)) #generator

# s = sorted(data1,reverse=True)
# print(s)
# s = sorted(data2,key=lambda n:n[0])
# print(s)
# s = sorted(data3,key=lambda n:n['kor'])
# print(s)


# mx = max(10,20,40,50)
# print(mx)
# mx = max( data1 )
# print(mx)
# mx = max( data2, key=lambda k:k[0])[0]
# print( mx)
# mx = max( data3, key=lambda k:k['eng'])['eng']
# print( mx)

--------------------------------------------------------------
#1. 십의 약수를 구하시오

for i in range(1,11):
    if 10%i == 0:
        print(i)

#2-1. cm를 입력받아 인치로 변환하시오
def inch(n):
    return n/2.54

#2-2. m를 입력받아 마일로 변환하시오
def mile(n):
    return n/1609.344

#2-3. 반지름과 높이를 입력받아 원기둥의 부피를 반환하시오.
def volumn(r,h):
    return r**2*h*3.14

#2-4. 년도를 입력받아 윤년인지 아닌지 반환
def year(n):
    if n % 4 == 0 and n % 100 != 0:
        return True
    elif n % 400 == 0:
        return True
    else:
        return False

def yoon(yesr):
    return "윤년" if(year % 4 == 0 and year % 100 != 0 ) or year %400 ==0 else "윤년 아님"


#3.
# 이름 :
# 국어 :
# 영어 :
# 계속입력(y/n):
# -------------------------
#   이름   국어     영어
# -------------------------
#   xxx     xx      xx


'''
 성적정보
----------
1. 입력
2. 출력
3. 검색
4. 종료
메뉴를선택하세요:

1)입력
이름:
국어:
영어:
계속입력(y/n):
'n'이면 메뉴

2)출력
======================================
   이름    국어     영어 총합  평균
=====================================
    홍길동  20       30 
....   
국어총합:
영어총합:
국어평균:
영어평균:

3) 
검색할 이름을 입력:
======================================
   이름    국어     영어 총합  평균
=====================================
    홍길동  20       30 
....

'''

info_list = []


def input_info():
    while 1:
        name = input('이름: ')
        kor = int(input('국어: '))
        eng = int(input('영어: '))

        info_list.append([name, kor, eng, kor + eng, (kor + eng) / 2])

        yn = input('계속입력(y/n): ')
        if yn == 'n':
            break;


def output_info():
    print('=' * 80, '{0:>10}{1:>10}{2:>10}{3:>10}{4:>10}'.format('이름', '국어', '영어', '총합', '평균'), '=' * 80, sep='\n')

    sub = []
    for name, kor, eng, sum_sub, avg_sub in info_list:
        sub.append([kor, eng])
        print('{0:>10}{1:>10}{2:>10}{3:>10}{4:>10}'.format(name, kor, eng, sum_sub, avg_sub))

    if len(info_list) > 0:
        print('국어 총합: ', sum([n[0] for n in sub]))
        print('영어 총합: ', sum([n[1] for n in sub]))
        print('국어 평균: ', sum([n[0] for n in sub]) / len(sub))
        print('영어 평균: ', sum([n[1] for n in sub]) / len(sub))


def search_info():
    input_name = input('검색할 이름을 입력(이름 부분 검색 적용 가능): ')
    print('=' * 80, '{0:>10}{1:>10}{2:>10}{3:>10}{4:>10}'.format('이름', '국어', '영어', '총합', '평균'), '=' * 80, sep='\n')

    for name, kor, eng, sum_sub, avg_sub in info_list:
        if input_name in name:
            print('{0:>10}{1:>10}{2:>10}{3:>10}{4:>10}'.format(name, kor, eng, sum_sub, avg_sub))
            break


print('성적정보', '-' * 10, '1. 입력', '2. 출력', '3. 검색', '4. 종료', sep='\n')
while (1):
    op = int(input('메뉴를 선택하세요: '))
    dic = {1: input_info, 2: output_info, 3: search_info}

    if op == 4:
        break

    dic[op]()
----------------------------------------------------
  성적정보(함수 기반으로 작성하시요)
----------
1. 입력
2. 출력
3. 검색
4. 종료
메뉴를선택하세요:

1)입력
이름:
국어:
영어:
계속입력(y/n):
'n'이면 메뉴

2)출력
======================================
   이름    국어     영어 총합  평균
=====================================
    홍길동  20       30 
....   
국어총합:
영어총합:
국어평균:
영어평균:

3) 
검색할 이름을 입력(이름부분검색도적용되야합니다):
======================================
   이름    국어     영어 총합  평균
=====================================
    홍길동  20       30 
....   


----------------------------------------------

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




