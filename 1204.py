-	파이썬의 특징
1.	객체지향 언어
2.	대화 기능의 인터프리터 언어
3.	동적인 데이터 타입 결정 지원
4.	플랫폼에 독립적
5.	개발 기간 단축에 초점
6.	간단하고 쉬움
7.	고 수준의 내장 객체 데이터 형
8.	메모리 자동 관리
-	변수 선언
a-z, A-Z, 0-9, _ , 한글, 숫자는 시작 X
기본 데이터 타입 : 정수, 실수, 불리안, 복소수

a = 10
print(a)    #내장 함수
print(type(a))
b = 1234563846902748973095709
c = 0x123
d = 0o123
e = 0b11

print(b)
print(c)
print(d)
print(e)

f=10
print(f)
print(hex(f))
print(oct(f))
print(bin(f))
f = 3.14
print(f)
print(type(f))

f = 3.0
print(f.is_integer())   # 3.14 -> false / 3.0 -> true

b = True    #False
print(b)
print(type(b))

a = 3+4j
print(a)
print(type(a))
print(a.imag)
print(a.real)
print(a.conjugate())


-	복합데이터타입

#1. 순서있는 (인덱스, 슬라이싱) : 문자열, 리스트, 튜플, bytes
#2. 순서없는 (인덱스, 슬라이싱 x) : 딕셔너리, 세트

#3. 변경가능(mutable) : 리스트, 세트, 딕셔너리
#4. 변경불가능(immutable) : 문자열, 튜플, bytes

s1 = 'abc' \
     'edf'
s2 = "abc" \
     "def"
s3 = '''abcedf'''
s4 = """abcdef"""

print(s1)
print(type(s1))
print(s2)
print(type(s2))

print(s3)
print(type(s3))
print(s4)
print(type(s4))

#i 012345678
#  -5-4-3-2-1
s = 'abcedfghi'
print( s[0] )
print( s[1])
print(s[-1])

#slice [시작인덱스:끝인덱스:증가치]
# 시작인덱스 <= index < 끝인덱스
print(s[1:4:1]) #1<= index < 4 (1,2,3)
print(s[1:4:2]) #1<= index < 4 (1,3)
print(s[1:5]) #증가치 생략 -> 1증가
print(s[:5])
print(s[:5:2]) #024
print(s[1:])


#############
s = 'abcdefghi'
s1 = '      abc     '
print(s1)
print(s1.strip())
#좌우 화이트스페이스(공백, \n, \r, \t) 제거 -> s1 자체가 변하지는 않음
s2 = '###abc###'

print(s2)
print(s2.strip('#'))

s3='abc def ghi'
print(s3.split())
#화이트스테이스 기준 자른다.

s4='000-1111-2222'
print(s4.split('-'))

#s[0] = 'A' -> immutable이기 때문에 불가능하다.

s5 = 'i like python like program'
print(s5.replace('like','love'))



-	Byte <-> 문자열 변환
#bytes (통신)
# app --write(send)--> 장치(시리얼통신), 호스트(소켓)
# str -> bytes (변환, 통신(바이트단위))

#app <---- read-- 장치(시리얼통신),호스트(소켓)
#bytes -> str (변환, 통신(바이트단위))

s = 'abc'
s = s.encode(encoding='utf-8') # byte단위로 변환해줌
print(s, type(s))
b = b'abc'
b=b.decode(encoding='utf-8')
print(b, type(b))


c=b'abc'
print(c[0])
print(chr(98))
print(ord('A'))


-	리스트 


myList = [10,20,30,40,50,20]


print(myList)
print(type(myList))
print(myList[0])
print(myList[-1])
print(myList[1:3]) #1,2
print(myList[1:])
print(myList[:4])


myList.append(60)   #끝에 추가
myList.append(70)
myList[0]=100
myList.insert(1,200)    #index위치에 증가


print(myList)


myList.remove(20)   #값을 삭제
myList.pop(3)    #index위치를 삭제
del(myList[2])  #del -> 파이썬 내장 함수
del(myList[1:3])
print(myList)


print(myList.count(20))
print(len(myList))
print(myList)
s='abcde'
print(len(s))
print(myList.index(20))     #여러개일 때 첫번째 index 출력
myList.append(20)
print(myList.index(20,2))


myList.sort(reverse=True)
print(myList)

print(myList.count(200))    #인자가 없으면 0을 출력한다.



-	튜플


t = (10,20,30,40,50)
print(t)
print(type(t))
print(t[0])
print(t[1:4])

# t[0]=100 --> 변경 불가능 하다

##

a = 10
b = 20
c = 30
print(a,b,c)
t1 = 1,2,3  #패킹 ( 튜플로 자동변환 )
print(t1)
a,b,c=(11,22,33)    #언패킹 (ㄱ
print(a,b,c)


-	set

s = {10,20,30,40,50,20,20}
print(s)            # 중복 데이터가 허용되지 않음
print(type(s))
#print(s[0])  -> 에러 ( index, slice X )

s1={10,20,30}
s2={20,30,40,50}
print(s1 & s2)  # 교집합
print(s1 | s2)  # 합집합
print(s1-s2)    #차집합


s.add(60)
s.add(70)
s.remove(20)
print(s)


-	딕셔너리


d = {'aa':10, 'bb':20, 'cc':30}
print(d)
print(type(d))
print(d['aa'])

'''
d['aa']=100     # 있으면 수정
d['dd']=400     # 없으면 추가

d1={}       #공백 딕셔너리
my=[]       #공백 리스트
s=set()     #공백 set

s.add(10)
d1['aa']=10
my.append(10)
print(s)
print(d1)
print(my)

'''

print(d.get('aa',1000))     #d['aa']
print(d.get('dd',1000))     #없으므로 default 값 1000을 반환
print(d.keys())             #key값을 뽑아냄
print(d.values())           #value값을 뽑아냄
print(d.items())            #값이 튜플로 들어있다.
d.pop('aa')                 #키와 해당 값이 삭제됨
print(d)


-	2차원 데이터 구조

d1 = [[10,20] , [30,40] , [50,60]]      #값 변경 가능
print(d1)
print(d1[0])
print(d1[0][0])
print(d1[2][1])

d2 = [ (10,20), (30,40), (50,60)]       #값 변경 불가
print(d2)
print(d2[0])
print(d2[0][0])
print(d2[2][1])

d3  = [ {'kor':10,'eng':20},
        {'kor': 30, 'eng': 40},
        {'kor': 50, 'eng': 60}]

print(d3)
print(d3[0])
print(d3[0]['kor'])

d4 = {'kor':[10,30,50],'eng':[20,40,60]}
print(d4)
print(d4['kor'])


-	연산자 우선 순위
-	a = 5

rst = a**2      #연산자 우선 순위가 제일 높음

rst = a*2
rst = a/2
rst = a%2
rst = a//2      #몫 연산자

rst = a + 2
rst = a - 2

print(rst)

rst = 3*2**2+10/2-3     #((3*(2**2)) + (10/2))-3
print(rst)


-	형 변환

n = '100'
n = int(n)
print(n, type(n))

s = 200
s = str(s)
print(s, type(s))

f='3.5'
f=float(f)
print(f, type)

t = (10,20,30)
t = list(t)
print(t, type)


-	표준 입력
-	n = input('입력: ')
print(n, type(n))       #입력값은 무조건 string으로 받는다.

# 연습 문제
#   반지름을 키보드로 입력 받아 원의 면적을 구하시오.

n = input('입력: ')
n = float(n)
d = n ** 2 * 3.14
print(d)


-	문자열 산술 연산자 & 포멧 연산자


s = 'abc'
s = s + 'def'       # 문자열 결합
print(s)

s = s*3             # 문자열 반복
print(s)

a = 10
b = 3.14
c = 'abc'
s1 = 'a=%d b=%.2f c=%10s'%(a,b,c)       # %는 포멧 연산자로 사용됨
s2 = f'a={a} b={b} c={c}'               # 3.5 버전 이후에 추가됨
print(s1)
print(s2)
d = {'name': '홍길동','age':20}
print( '이름:%(name)s 나이:%(age)d'%d)

my=[10,20,30]
my = my + [1,2,3]

my = my * 3
print(my)



-	관계 연산자

a = 15
rst = a > 0

# >, >=, < , <= , == , !=
rst = 0 < a < 10     # c언어에서는  0<a && a<10
print(rst)

# 요소값 in 복합데이터타입
my = [10,20,30]
print(20 in my)     # 있으면 True 없으면 False

s = "hello python"
print('llo' in s)
d = {'aa':10, 'bb':20, 'cc':30}
print('aa' in d)
print( 10 in d.values())


-	논리 연산자

a = 5
rst = a>0 and a==5
rst2 = a>0 or a==5
rst3 = not a>0      # c언어 !a>0
print( rst )
print(rst2)



# False : None , 0, [], {}, ''
# True : 10,3.14, [10,20],{'aa':20}, 'aa'

b = None
rst = not 'abc' # False


-	축약형 IF문

# int a = 5;
# int rst;
# rst = a>0 ? 100 : 200;

a = 5
rst = 100 if a>0 else 200
print(rst)

b = True + 1        #True 는 1 , False는 0으로 본다.
print(b)

rst = [200,100][a>0]
print(rst)

rst= {True:200,False:100}[a>0]
print(rst)


# 연습문제
#  점수를 입력받아 70점 이상이면 '합격' 아니면 '불합격'

score=int(input('점수:'))
msg = '합격' if score>=70 else '불합격'
rst = ['불합격','합격'][score>=70]
print(msg)

-	제어문

a = 5
if a>0 :
    print("크다")
elif a==0:
    print('같다')
else:
    print('작다')

print('hello')

# 연습 문제
#   하나의 점수를 읽어 90~100 : 'A' 80~89 : B 70~79 : C 60~69 : D 50~69 : F

score = int(input("점수:"))
if 90<=score<=100:
    print('A')
elif 80 <= score <= 89:
    print('B')
elif 70<=score<=79:
    print('C')
elif 60 <= score <= 69:
    print('D')
else:
    print('F')


# switch문을 지원하지 않는다. 딕셔너리를 사용하면 되기 때문

d={1:'1번 선택',2:'2번 선택',3:'3번 선택'}
print(d[1])


# 연습 문제
#   위의 문제를 딕셔너리 이용하여 해결하시오
score1 = int(input("점수:"))
d={10:'A',9:'A',8:'B',7:'C',6:'D'}
print(d.get(score1//10,'F'))


-	연습문제

#1 키와 몸무게를 입력받아 비만도를 구하고 결과를 출력하시오.

h = float(input('키 입력: '))
w = float(input('몸무게 입력: '))

standard_w = (h - 100) * 0.85
fat = w / standard_w * 100

if fat <= 90:
    print('저체중')
elif 90 < fat <= 110:
    print('정상')
elif 110 < fat <= 120:
    print('과체중')
else:
    print('비만')


#2.1 cm를 입력받아 인치로 변환하시오
cm = float(input("cm를 입력하시오 : "))
print(format(cm/2.54, ".2f"), "inch 입니다.")


#2.2 m를 입력받아 마일로 변환하시오
m = float(input("m를 입력하시오 : "))
print(format(m/1609.344, ".6f") + "inch 입니다.")

#2.3 화씨를 입력받아 도로 변환하시오
F = float(input("F씨를 입력하시오 : "))
print(format((F - 32)/(5/9), ".2f"), "도씨 입니다.")


#3.1 반지름과 높이를 입력받아 원기둥의 부피 / 3.2 원뿔의 부피
r = int(input('반지름 : '))
h = int(input('높이 :'))
print('원기둥의 부피 : ', r**2*3.14*h)
print('원뿔의 부피 : ', r**2*3.14*h*(1/3))

#3.3 가로,세로,높이를 입력받아 사각기둥의 부피
a = int(input('가로 : '))
b = int(input('세로 : '))
h = int(input('높이 : '))
print('사각기둥의 부피 : ', a*b*h)

#3.4 2개의 정수를 입력 받아 절대값의 합
x = int(input('x :'))
y = int(input('y :'))
x = x if x>0 else x*(-1)
y = y if y>0 else y*(-1)
print('절대값의 합 : ', x+y)

#3.5 3개의 정수를 입력 받아 가장 큰 값
x = int(input('x :'))
y = int(input('y :'))
z = int(input('z :'))
max1 = x if x>y else y
max = z if z>max1 else max1
print('최대값 : ', max)

#5 상품가격과 지불액을 입력받아 거스름돈을 최소화 하도록 잔돈의 갯수를 구하시오.

price = (int)(input("상품가격 : "))
paid = (int)(input("지불액 : "))

change  = paid - price
c = change
m500 = (int) (change / 500)

change %= 500

m100 = (int) (change / 100)
change %= 100

m50 = (int) (change / 50)
change %= 50

m10 = (int) (change / 10)
change %= 10


print("잔돈은 ",c,"원", "500원 ", m500,"개", "100원",m100,"개","50원",m50,"개","10원",m10,"개")




#6

myList = []

while 1:
    name = input('이름: ')
    kor = input('국어: ')
    eng = input('영어: ')
    math = input('수학: ')

    mySubList = []
    mySubList.append(name)
    mySubList.append(kor)
    mySubList.append(eng)
    mySubList.append(math)

    myList.append(mySubList)
    rst = input('계속입력(y/n)?')
    if rst == 'n':
        break

print('이름 국어 영어 수학')
sub=[]
for sub in myList:
    print(sub[0], sub[1], sub[2], sub[3])
