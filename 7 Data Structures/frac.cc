#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd (ll a, ll b) {
	return __gcd(a,b);
}

struct frac { 
	ll num,den;

	frac(ll n, ll d = 1) {
		num = n;
		den = d;
		reduce();
	}

	void reduce(){
		if (den < 0) {
			num *= -1;
			den *= -1;
		}

		ll g = gcd(num, den);
		
		num /= g;
		den /= g;	
	}

	void recip() {
		ll tmp = num;
		num = den;
		den = tmp;
	}
};

frac operator+ (frac a, frac b) {
	ll den = a.den * b.den;
	ll num = a.num * b.den + b.num * a.den;
	return {num.den};
}

frac operator- (frac a, frac b) {
	ll den = a.den * b.den;
	ll num = a.num * b.den - b.num * a.den;
	return {num,den};
}

frac operator* (frac a, frac b) {
	ll g1 = gcd(a.den, b.num);
	ll g2 = gcd(a.num, b.den);
	ll num = a.num/g2 * b.num/g1;
	ll den = a.den/g1 * b.den/g2;
	return {num,den};
}

frac operator/ (frac a, frac b) {
	return a * b.recip();
}

bool operator== (frac a, frac b) {
	return (a.num == b.num && a.den == b.den);
}

//May cause overflow
bool operator< (frac a, frac b){
	return (a.num * b.den < b.num * a.den);
}

//May cause round issue
bool operator< (frac a, frac b){
	return (!a==b && a.num/1.0/a.den < b.num/1.0/b.den);
