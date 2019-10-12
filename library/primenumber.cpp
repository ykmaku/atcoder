//素数判定
bool is_prime(ll n){
	if (n == 1){
		return false;
	}

	for(int i = 2; i * i <= n; i++){
		if (n % i == 0) return false;
	}

	return true;
}

//約数列挙 O(\sprt(n))
vector<int> divisor(int n)
{
	vector<int> res;

	for(int i = 1; i * i <= n; i++)
	{
		if (n % i==0)
		{
			res.push_back(i);
			if (i != n / i)
			{
				res.push_back(n / i);
			}
		}
	}

	sort(all(res));  //O(\sprt(n)log(n))

	return res;
}


//素因数分解
map<int, int> prime_factor(int n)
{
	map<int, int> res;

	for(int i = 2; i * i <= n; i++)
	{
		while(n % i == 0)
		{
			++res[i];
			n /= i;
		}
	}

	if (n != 1)
	{
		res[n] = 1;
	}

	return res;
}
