
//確率版
double C[1010][1010] = {};  //C[n][k] == nCk

void pascal(ll n){
	double div = 2.0;
	C[0][0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= n; j++){
			if(i<j) C[i][j] = 0;
			else if(j==0||i==j) C[i][j] = 1/div;
			else{
				C[i][j] = C[i-1][j-1] + C[i-1][j];
				C[i][j] /= 2;
			}
		}
		div *= 2;
	}
}


ll C[1010][1010] = {};  //C[n][k] == nCk

void pascal(ll n){
	C[0][0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= n; j++){
			if(i<j) C[i][j] = 0;
			else if(j==0||i==j) C[i][j] = 1;
			else{
				C[i][j] = C[i-1][j-1] + C[i-1][j];
			}
		}
	}
}
