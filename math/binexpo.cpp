/*
This code uses binary exponentiation as well as modular exponentiation.
*/
long long int powmod(long long base,long long power,int mod){
	long long ans=1;
	while(power>0){
		if(power&1){ans = ans * base % mod;}
		power >>= 1;
		base = base * base %mod;
	}
	return ans;
}
