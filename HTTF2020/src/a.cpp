#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<(b);i++)
#define repr(i,b,a) for(int i=int(b);i>=(a);i--)
#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const double TIME_LIMIT = 2990;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
vector<int> d_index={0,1,2,3};


//input
int N=40,M,B;
int GoalX,GoalY;
char dir[5]={'R','U','L','D','Z'};

typedef class Robot{
public:
	int x,y;
	int N=40;
	char direction;
	bool feasible;
	bool goaled=false;
	Robot(int xx,int yy,char d):x(xx),y(yy),direction(d),feasible(true){};
	void Move(){
		if(direction=='U')y=(y-1+N)%N;
		else if(direction=='D')y=(y+1+N)%N;
		else if(direction=='L')x=(x-1+N)%N;
		else if(direction=='R')x=(x+1+N)%N;
	}
	void ChangeDirection(char d){
		direction=d;
	}
	void Infeasible(){
		feasible=false;
	}
	void goal(){
		goaled=true;
	}
}Robot;

string normal="normal",block="block",goal="goal",sign="sign";

typedef struct Square{
	/*
	status  :	normal
			:	block
			:	goal
			:	sign
	*/
	int x,y;
	string status;
	char direction;
	int is_walked=0;
	Square(int x,int y,string status,char direction):x(x),y(y),status(sign),direction(direction){};
	Square(){x=0,y=0,status=normal,direction='.';};
}Square;

///input
vector<Robot> all_robot;
vector<vector<Square>> Board(40,vector<Square>(40));

///シミュレーター
int SimulateRobot(vector<vector<Square>> &CurrentBoard, Robot robot){
	/*
	盤面上でロボットを動かす
	*/
	Robot current_robot=robot;
	set<P> walked;
	while(current_robot.feasible){
		int y=current_robot.y,x=current_robot.x;
		CurrentBoard[current_robot.y][current_robot.x].is_walked=1;
		if(CurrentBoard[y][x].status==sign){
			if(walked.count(P(y,x))!=0){
				current_robot.Infeasible();
				continue;
			}
			char dir=CurrentBoard[y][x].direction;
			current_robot.ChangeDirection(dir);
		}
		walked.insert(P(y,x));
		current_robot.Move();
		if(CurrentBoard[current_robot.y][current_robot.x].status==block){
			CurrentBoard[current_robot.y][current_robot.x].is_walked=0;
			current_robot.Infeasible();
			continue;
		}


		if(CurrentBoard[current_robot.y][current_robot.x].status==goal){
			current_robot.Infeasible();
			current_robot.goal();
		}
	}
	return (current_robot.goaled?1:0);
}

int Eval(vector<vector<Square>> &CurrentBoard){

	int goaled_robot=0;
	int sign_count=0;
	int walked_square=0;

	for(auto robot:all_robot){
		goaled_robot+=SimulateRobot(CurrentBoard,robot);
	}
	rep(i,40)rep(j,40){
		walked_square += CurrentBoard[i][j].is_walked;
		CurrentBoard[i][j].is_walked=0;

		if(CurrentBoard[i][j].status==sign)sign_count++;
	}
	if(goaled_robot<100)return 0;
	return 1000*goaled_robot - 10*sign_count;
}

int CalcScore(vector<vector<Square>> &CurrentBoard){
	/*
		盤面評価
	*/
	int goaled_robot=0;
	int sign_count=0;
	int walked_square=0;

	for(auto robot:all_robot){
		goaled_robot+=SimulateRobot(CurrentBoard,robot);
	}
	rep(i,40)rep(j,40){
		walked_square += CurrentBoard[i][j].is_walked;
		CurrentBoard[i][j].is_walked=0;

		if(CurrentBoard[i][j].status==sign)sign_count++;
	}

	// cout<<"Goaled Robot = "<<goaled_robot<<endl;
	if(goaled_robot<100)return 0;
	return 1000*goaled_robot - 10*sign_count + walked_square;
}



void Input(){
	cin>>N>>M>>B;
	cin>>GoalY>>GoalX;
	rep(i,M){
		int x,y;
		char d;
		cin>>y>>x>>d;
		all_robot.push_back(Robot(x,y,d));
	}
	random_device rd;
	mt19937 mt(rd());
	// uniform_int_distribution<int> random_dir(0,4);
	rep(i,40)rep(j,40)Board[i][j]=Square(i,j,normal,dir[0]);

	Board[GoalY][GoalX].status=goal;
	rep(i,B){
		int x,y;
		cin>>y>>x;
		Board[y][x].status=block;
	}
}

void Output(vector<vector<Square>> &CurrentBoard,bool output){
	vector<tuple<int,int,char>> result;
	rep(y,N)rep(x,N){
		if(CurrentBoard[y][x].status==sign){
			result.push_back(make_tuple(y,x,CurrentBoard[y][x].direction));
		}
	}

	if(output){
		cout<<result.size()<<endl;
		rep(i,result.size())cout<<get<0>(result[i])<<" "<<get<1>(result[i])<<" "<<get<2>(result[i])<<endl;
	}

	ofstream file("./test/output.txt");
	file<<result.size()<<endl;
	rep(i,result.size())file<<get<0>(result[i])<<" "<<get<1>(result[i])<<" "<<get<2>(result[i])<<endl;
}


///計算
tuple<int,int,char> random_sample(){
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> random_point(0,40*40-1),random_dir(0,4);
	int RandomP = random_point(mt);
	int c=random_dir(mt);
	tuple<int,int,char> ret=make_tuple(RandomP/N,RandomP%N,dir[c]);
	return ret;
}



void bfs(int gx,int gy,vector<vector<Square>>&Board){
	queue<P> que;
	vector<vector<int>> used(40,vector<int>(40,0));
	que.push(P(gy,gx));
	used[gy][gx]=1;

	rep(i,40)rep(j,40){
		if(Board[i][j].status==block)used[i][j]=1;
	}

	random_device rd;
	mt19937 mt(rd());
	int cnt=0;
	while(!que.empty()){
		P p = que.front();que.pop();
		int y=p.first,x=p.second;

		shuffle(all(d_index),mt);
		rep(i,4){
			int j=d_index[i];
			int ny=(y+dy[j]+N)%N;
			int nx=(x+dx[j]+N)%N;
			if(used[ny][nx]==0){
				que.push(P(ny,nx));
				used[ny][nx]=1;

				if(dy[j]<0)Board[ny][nx].direction='D';
				else if(dy[j]>0)Board[ny][nx].direction='U';
				else if(dx[j]<0)Board[ny][nx].direction='R';
				else if(dx[j]>0)Board[ny][nx].direction='L';
			}
		}
	}
}



void Greedy(){
	/*
	ランダムに点をピックして、その中で一番良い盤面になるところに看板を置く
	*/
	int current_score = Eval(Board);
	int Num_iterate=7500;
	while(Num_iterate--){
		vector<vector<Square>> eval_Board=Board;
		int current_eval_score=current_score;
		rep(j,3){
			tuple<int,int,char> sample=random_sample();
			int y=get<0>(sample),x=get<1>(sample);
			char direction=get<2>(sample);
			if(Board[y][x].status!=sign)continue;
			vector<vector<Square>> CurrentBoard = Board;

			random_device rd;
			mt19937 mt(rd());
			bernoulli_distribution Coin(0.6);
			bernoulli_distribution Coin2(0.6);
			if(Coin(mt)){
				CurrentBoard[y][x].status=normal;
				int target_score=Eval(CurrentBoard);
				if(current_eval_score<target_score) current_eval_score=target_score,eval_Board=CurrentBoard;
				else if(current_eval_score==target_score&&Coin2(mt))current_eval_score=target_score,eval_Board=CurrentBoard;
			}else{
				if(CurrentBoard[y][x].direction=='U'||CurrentBoard[y][x].direction=='D'){
					vector<vector<Square>> LeftBoard = Board;
					Square left=LeftBoard[y][(x-1+N)%N];
					int left_score=0;
					if(left.status==normal){
						LeftBoard[y][x].status=normal;
						LeftBoard[y][(x-1+N)%N].status=sign;
						LeftBoard[y][(x-1+N)%N].direction=LeftBoard[y][x].direction;
						left_score=Eval(LeftBoard);
					}
					vector<vector<Square>> RightBoard = Board;
					Square right=RightBoard[y][(x+1+N)%N];
					int right_score=0;
					if(right.status==normal){
						RightBoard[y][x].status=normal;
						RightBoard[y][(x+1+N)%N].status=sign;
						RightBoard[y][(x+1+N)%N].direction=RightBoard[y][x].direction;
						right_score=Eval(RightBoard);
					}
					if(left_score>right_score){
						if(left_score>current_eval_score)eval_Board=LeftBoard;
						else if(left_score==current_eval_score&&Coin2(mt))eval_Board=LeftBoard;
					}else{
						if(right_score>current_eval_score)eval_Board=RightBoard;
						else if(right_score==current_eval_score&&Coin2(mt))eval_Board=RightBoard;
					}
				}else{
					vector<vector<Square>> UpperBoard = Board;
					Square upper=UpperBoard[(y-1+N)%N][x];
					int upper_score=0;
					if(upper.status==normal){
						UpperBoard[y][x].status=normal;
						UpperBoard[(y-1+N)%N][x].status=sign;
						UpperBoard[(y-1+N)%N][x].direction=UpperBoard[y][x].direction;
						upper_score=Eval(UpperBoard);
					}
					vector<vector<Square>> DownBoard = Board;
					Square down=DownBoard[(y+1+N)%N][x];
					int down_score=0;
					if(down.status==normal){
						DownBoard[y][x].status=normal;
						DownBoard[(y+1+N)%N][x].status=sign;
						DownBoard[(y+1+N)%N][x].direction=DownBoard[y][x].direction;
						down_score=Eval(DownBoard);
					}
					if(upper_score>down_score){
						if(upper_score>current_eval_score)eval_Board=UpperBoard;
						else if(upper_score==current_eval_score&&Coin2(mt))eval_Board=UpperBoard;
					}else{
						if(down_score>current_eval_score)eval_Board=DownBoard;
						else if(down_score==current_eval_score&&Coin2(mt))eval_Board=DownBoard;
					}
				}
			}

		}
		Board=eval_Board;
	}
}



void DeleteNoUsedSign(vector<vector<Square>> &CurrentBoard,bool all){
	for(auto robot:all_robot){
		SimulateRobot(CurrentBoard,robot);
	}

	double prob=(all?1.0:0.2);
	random_device rd;
	mt19937 mt(rd());
	bernoulli_distribution Coin(prob);
	int del_count=0;
	rep(i,40)rep(j,40){
		if(CurrentBoard[i][j].is_walked==0&&CurrentBoard[i][j].status==sign&&Coin(mt))CurrentBoard[i][j].status=normal,del_count++;
		CurrentBoard[i][j].is_walked=0;
	}
}



int main()
{
	// clock_t start = clock();

	Input();
	bfs(GoalX,GoalY,Board);
	// cout<<"Base Score = "<<Eval(Board)<<endl;
	// DeleteNoUsedSign(Board,false);
	// DeleteOneDirectionSign(Board);
	Greedy();
	DeleteNoUsedSign(Board,true);
	// Output(Board,false);
	Output(Board,true);
	// cout<<"Score = "<<CalcScore(Board)<<endl;

	// clock_t end = clock();

    // const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    // printf("time %lf[ms]\n", time);

	return 0;
}
