//作业：大整数，比如9081321110693270343633073697474256143563558458718976746753830538032062222085722974121768604305613921745580037409259811952655310075487163797179490457039169594160088430571674960498834085812920457916453747019461644031395307920624947349951053530086146486307198155590763466429392673709525428510973272600608981219760099374675982933766845473509473676470788342281338779191792495900393751209539300628363443012 6538005862664913074813656220643842443844131905754565672075358391135537108795991638155474452610874309742867231360502542308382199053675592825240788613991898567277116881793749340807728335795394301261629479870548736450984003401594705923178314906195914825136973281314862289454100745237769034410057080703111299605127114594552921209928891515242515620324828055912854227507525717981351447473570262981491527798 
//重新设计下面的代码，使其可以处理大整数的素数与超级素数
//同时仔细理解面向对象的编程方式 
#include <iostream>
#include<cstring>
#include<algorithm>

#define MAXN 9999 	//每个元素的表示最大值 

class BigInteger{
public:
	BigInteger() : digit_len(0) { memset(digit, 0, sizeof(digit));}
	BigInteger(const int);
	BigInteger(const BigInteger&);
	BigInteger &operator=(const BigInteger &);
	~BigInteger();
	
	friend std::istream &operator>>(std::istream&, BigInteger&);
	friend std::ostream &operator<<(std::ostream&, BigInteger&);
	
	BigInteger operator+(BigInteger&);
	BigInteger operator-(BigInteger&);
	BigInteger operator*(BigInteger&);
	BigInteger operator/(int&);
	BigInteger operator%(int&);
	bool operator>(const BigInteger&)const;
	bool operator>(const int &)const;
	bool operator==(const BigInteger&)const;
	bool operator!=(const BigInteger&)const;
	
	BigInteger getsum();
	BigInteger getmulti();
	BigInteger getsquareSum();
private:
	int digit[500];//每个digit最大表示9999 
	int digit_len;
};
class BigPrime {
public:
  BigPrime(BigInteger n) : num(n){
  }
  BigPrime(int n) : num(n){
  }
  virtual ~BigPrime(){} 
  virtual bool isPrime() const {
    	int i;
		BigInteger number(num);
		BigInteger zero(0);
		for(i = 2; number > i; i++){
			if(number % i == zero) break;
		} 
		BigInteger temp(i);
		if(temp != number) return false;
		return true;
  }
private:
  const BigInteger num;
}; 
class BigSuperPrime : public BigPrime {
public:
  BigSuperPrime(BigInteger n) : BigPrime(n), num(n){
  }
  BigSuperPrime(int n) : BigPrime(n), num(n){
	BigInteger temp(n);
	sum = new BigPrime(temp.getsum());
	multi = new BigPrime(temp.getmulti());
	squareSum = new BigPrime(temp.getsquareSum());
  }
  virtual ~BigSuperPrime(){
  	delete sum;
  	delete multi;
  	delete squareSum;
  }
  virtual bool isPrime() const {
    if(BigPrime::isPrime() 
		&& sum->isPrime() 
		&& multi->isPrime() 
		&& squareSum->isPrime())
		return true;
	return false;
  }
private:
  const BigInteger num;
  BigPrime *sum;
  BigPrime *multi;
  BigPrime *squareSum;
};
class Set {
public:
  Set(int sz);
  ~Set();
  bool add(BigPrime *bp);
  bool remove(BigPrime *bp);
  int count() const {
  	int ret = 0;
  	for (int i = 0; i < index; i++) {
  	  if (pset[i]->isPrime())
  	    ret += 1;
	  }
  	return ret;
  }
  int sum() const {
  	return 0;
  } 
private:
  BigPrime **pset;
  int size, index;
};

int main() {
  Set set(1000);
  BigPrime bp(2);
  BigSuperPrime bp1(13);
  set.add(&bp);
  set.add(&bp1);
  std::cout << set.count() << std::endl;
  return 0;
} 

Set::Set(int sz):size(sz) {
  index = 0;
  pset = new BigPrime*[size];  //分配存储空间 
}

Set::~Set() {
  delete[] pset;  //回收 
}
bool Set::add(BigPrime *bp) {
  pset[index++] = bp;
  return true;
}

BigInteger::BigInteger(const int n){
	int i = 0;
	int number = n;
	memset(digit, 0, sizeof(digit));
	for(i = 0; number > MAXN; i++){ 
		digit[i] = number % (MAXN + 1);
		number /= (MAXN + 1);
	}
	digit[i] = number;
	digit_len = i + 1;
}
BigInteger::BigInteger(const BigInteger& bint){
	int i = 0;
	memset(digit, 0, sizeof(digit));
	digit_len = bint.digit_len;
	for(i = 0; i < digit_len; i++){ 
		digit[i] = bint.digit[i];
	}
}
BigInteger & BigInteger::operator=(const BigInteger & bint){
	digit_len = bint.digit_len;
	memset(digit, 0, sizeof(digit));
	int i;
	for(i = 0; i < digit_len; i++){
		digit[i] = bint.digit[i];
	}
	return *this;
}

BigInteger::~BigInteger(){
}
std::istream &operator>>(std::istream& in, BigInteger& bint){
	char c[500];//先作为字符存储，在逐位转换 
	std::cin >> c;
	int len = strlen(c);
	int i, j;
	int index = 0;
	for(i = len - 1; i > 0; ){
		for(j = 0; j < 4 && i >= 0; j++, i--){
			bint.digit[index] += (c[i] - '0') * pow(10, j);
		}
		index++;
	}
	bint.digit_len = index;
	return in;
}
std::ostream &operator<<(std::ostream& out, BigInteger& bint){
	int i;
	for(i = bint.digit_len - 1; i >= 0; i--){
		if(bint.digit[i] == 0 && bint.digit[bint.digit_len - 1] != 0) 
			std::cout << 0 << 0 << 0 << 0; //当该位为0且不是整个大数字不是0时 
		else if(bint.digit[i] < 10 && i != bint.digit_len - 1) 
			std::cout << 0 << 0 << 0 << bint.digit[i];
		else if(bint.digit[i] < 100 && i != bint.digit_len - 1) 
			std::cout << 0 << 0 << bint.digit[i];
		else if(bint.digit[i] < 1000 && i != bint.digit_len - 1) 
			std::cout << 0 << bint.digit[i];
		else std::cout << bint.digit[i];
	}
	return out;
}
BigInteger BigInteger::operator+(BigInteger& bint){
	BigInteger sum(*this);//this为第一个运算数，bint为第二个运算数 
	int i = 0;
	for(i = 0; i < sum.digit_len && i < bint.digit_len; i++){
		if(sum.digit[i] + bint.digit[i] > MAXN){
			sum.digit[i+1] += 1;	//进位 
			sum.digit[i] = (sum.digit[i] + bint.digit[i]) % (MAXN + 1); 
		}else{
			sum.digit[i] = sum.digit[i] + bint.digit[i];
		}	
	}
	return sum;
}
BigInteger BigInteger::operator-(BigInteger& bint){
	BigInteger difference(*this);//this为第一个运算数，bint为第二个运算数 
	int i = 0;
	if(difference > bint){
		for(i = 0; i < difference.digit_len && i < bint.digit_len; i++){
			if(difference.digit[i] - bint.digit[i] < 0){
				difference.digit[i+1] -= 1;	//借位 
				difference.digit[i] = difference.digit[i] + MAXN + 1 - bint.digit[i]; 
			}else{
				difference.digit[i] = difference.digit[i] - bint.digit[i];
			}	
		}
	} else{
		for(i = 0; i < difference.digit_len && i < bint.digit_len; i++){
			if(bint.digit[i] - difference.digit[i] < 0){
				bint.digit[i+1] -= 1;	//借位 
				bint.digit[i] = bint.digit[i] + MAXN + 1 - difference.digit[i]; 
			}else{
				bint.digit[i] = bint.digit[i] - difference.digit[i];
			}	
		}
		bint.digit[bint.digit_len - 1] = 0 - bint.digit[bint.digit_len - 1];
		difference = bint;
	}
	while(difference.digit[difference.digit_len-1] == 0 && difference.digit_len > 1) 
			difference.digit_len --;//消除-运算后的0位 
	return difference;
}
BigInteger BigInteger::operator*(BigInteger& bint){
	BigInteger multi;
	int i, j, carry;
	int temp;//不使用temp而直接使用表达式出现数据错误，猜测 
	for(i = 0; i < digit_len; i++){
		carry = 0;
		for(j = 0; j < bint.digit_len; j++){
			temp = digit[i] * bint.digit[j] + multi.digit[i + j] + carry;
			if(temp > MAXN){
				carry =  temp / (MAXN + 1);
				multi.digit[i + j] = temp % (MAXN + 1);
			}else{
				carry = 0;
				multi.digit[i + j] = temp;
			}
		}
		if(carry != 0) multi.digit[i + j] = carry;
	}
	multi.digit_len = i + j;
	while(multi.digit[multi.digit_len-1] == 0 && multi.digit_len > 1) 
		multi.digit_len --;//消除0位
	return multi;
}
BigInteger BigInteger::operator/(int & num){
	BigInteger quotient;
	int i, remainder = 0;
	for(i = digit_len - 1; i >= 0; i--){
		if((digit[i] + remainder * (MAXN + 1)) % num == 0) {
			quotient.digit[i] = (digit[i] + remainder * (MAXN + 1)) / num;
		}else {
			quotient.digit[i] = (digit[i] + remainder * (MAXN + 1)) / num;
			remainder = (digit[i] + remainder * (MAXN + 1)) % num;
		}
	}
	quotient.digit_len = digit_len;	
	while(quotient.digit[quotient.digit_len-1] == 0 && quotient.digit_len > 1) 
		quotient.digit_len --;//消除0位
	return quotient; 
}
BigInteger BigInteger::operator%(int & num){
	BigInteger remainder;
	int i, Remainder = 0;
	for(i = digit_len - 1; i >= 0; i--){
		if((digit[i] + Remainder * (MAXN + 1)) % num == 0) {
			Remainder = 0;
		}else {
			Remainder = (digit[i] + Remainder * (MAXN + 1)) % num;
		}
	}
	remainder.digit_len = digit_len;	
	while(remainder.digit[remainder.digit_len-1] == 0 && remainder.digit_len > 1) 
		remainder.digit_len --;//消除0位
	return remainder;
}
bool BigInteger::operator>(const BigInteger & bint)const{ 
	int len; 
	if(digit_len > bint.digit_len)
		return true; 
	else if(digit_len == bint.digit_len)
	{ 
		len = digit_len - 1; 
		while(digit[len] == bint.digit[len] && len >= 0)
			len--; 
		if(len >= 0 && digit[len] > bint.digit[len])
			return true; 
		else
			return false; 
	} 
	else
		return false; 
}
bool BigInteger::operator>(const int & num) const{
	BigInteger number(num);
	return *this > number;
}
bool BigInteger::operator==(const BigInteger & num) const{
	if(digit_len != num.digit_len) return false;
	int i;
	for(i = digit_len - 1; i >= 0; i--){
		if(digit[i] != num.digit[i]) return false;
	}
	return true;
}
bool BigInteger::operator!=(const BigInteger & num) const{
	if(*this == num) return false;
	return true;
}
BigInteger BigInteger::getsum(){
	BigInteger sum;
	int i, j;
	int temp;
	for(i = 0; i < digit_len; i++){
		temp = digit[i];
		for(j = 0; j < 4; j++){
			int temp1 = temp % 10;
			BigInteger t(temp1);
			temp /= 10;
			sum = t + sum;
		}
	}
	return sum;
}
BigInteger BigInteger::getmulti(){
	BigInteger multi(1);
	int i, j;
	int temp;
	for(i = 0; i < digit_len; i++){
		temp = digit[i];
		for(j = 0; j < 4; j++){
			int temp1 = temp % 10;
			BigInteger t(temp1);
			temp /= 10;
			multi = multi * t;
		}
	}
	return multi;
}
BigInteger BigInteger::getsquareSum(){
	BigInteger squareSum;
	int i, j;
	int temp;
	for(i = 0; i < digit_len; i++){
		temp = digit[i];
		for(j = 0; j < 4; j++){
			int temp1 = temp % 10;
			BigInteger t(temp1 * temp1);
			temp /= 10;
			squareSum = t + squareSum;
		}
	}
	return squareSum;
}
