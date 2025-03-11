#include<bits/stdc++.h>
using namespace std;
const int N=100009;
struct files{
	string name;
	vector<int> to;
	int op;
} fs[N];
struct file{
	string l,r;
	vector<string> data;
	int op; 
} f[N];
struct exe{
	string name;
	vector<string> data;
	int op;
} e[N];
int next=1,all_file,now,exe_,now_op;
string start;
bool l=true;
vector<int> pos;
vector<int> EXE;
vector<int> POS;
void input(){
	int n;
	cin>>n;
	all_file=n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		int num;
		cin>>num;
		next=max(next,num+1);
		if(c=='f'){
			cin>>f[num].op>>f[num].l>>f[num].r;
			int m;
			cin>>m;
			string v;
			getline(cin,v);
			for(int i=1;i<=m;i++){
				string s;
				getline(cin,s);
				f[num].data.push_back(s); 
			}
		}
		if(c=='s'){
			cin>>fs[num].op>>fs[num].name;
			int m;
			cin>>m;
			for(int i=1;i<=m;i++){
				int x;
				cin>>x;
				fs[num].to.push_back(x);
			}
		}
		if(c=='e'){
			cin>>e[num].op>>e[num].name;
			int m;
			cin>>m;
			for(int i=1;i<=m;i++){
				string x;
				cin>>x;
				e[num].data.push_back(x);
			}
			m++;
			e[num].data.push_back("break");
		}
	}
	system("cls");
}
void IN(string &s,int EXE_){
	if(EXE_==0)cin>>s;
	else{
		s=e[EXE_].data[now++];
	}
}
void output(){
	freopen("system.dll","w",stdout);
	cout<<start<<endl; 
	cout<<all_file<<endl;
	for(int i=1;i<next;i++){
//		cout<<2<<endl;
		if(f[i].l==""&&fs[i].name==""&&e[i].name=="")continue;
		if(f[i].l!=""){
			cout<<"f "<<i<<" "<<f[i].op<<" "<<f[i].l<<" "<<f[i].r<<" "<<f[i].data.size()<<endl;
			for(int j=0;j<f[i].data.size();j++){
				cout<<f[i].data[j]<<endl;
			}
		}
		else if(fs[i].name!=""){
			cout<<"s "<<i<<" "<<fs[i].op<<" "<<fs[i].name<<" "<<fs[i].to.size();
			for(int j=0;j<fs[i].to.size();j++){
				cout<<" "<<fs[i].to[j];
			}
			cout<<endl;
		}
		else if(e[i].name!=""){
			cout<<"e "<<i<<" "<<e[i].op<<" "<<e[i].name<<" "<<e[i].data.size();
			for(int j=0;j<e[i].data.size();j++){
				cout<<" "<<e[i].data[j];
			}
			cout<<endl;
		}
//		cout<<1<<endl;
	}
//	cout<<" ";
}
int main(){
	cout<<"Do you want to res?(Y/N)\n";
	char c;
	cin>>c;
	if(c=='Y'){
		start="start";
		next=2;
		all_file=1;
		f[1].l="";
		f[1].r="";
		f[1].op=0;
		f[1].data.clear();
		fs[1].name="C:";
		fs[1].op=0;
		fs[1].to.clear();
		output();
		return 0;
	}
//	cout<<"Please copy all things in \"system.dll\" and enter in this.\n";
	freopen("system.dll","r",stdin);
	cin>>start;
	input();
	freopen("CON","r",stdin);
	pos.push_back(1);
	int x=0;
	now_op=2;
	for(int i=0;i<fs[pos[pos.size()-1]].to.size();i++){
		if(e[fs[pos[pos.size()-1]].to[i]].name==start){
			x=fs[pos[pos.size()-1]].to[i];
		}
	}
	now_op=0;
	exe_=x;
	if(x)EXE.push_back(0),POS.push_back(0);
	EXE.push_back(x);
	POS.push_back(0);
	while(true){
//		cout<<"[log]\n";
//		output();
//		cout<<endl; 
		if(l){
			cout<<fs[pos[0]].name;
			for(int i=1;i<pos.size();i++){
				cout<<"\\"<<fs[pos[i]].name;
			}
			cout<<">";
		}
		string s;
		IN(s,exe_);
//		cout<<s<<endl; 
		if(s=="fa"){
			if(pos.size()!=1)pos.pop_back();
		}
		if(s=="to"){
			string x;
			IN(x,exe_);
			for(int i=0;i<fs[pos[pos.size()-1]].to.size();i++){
				if(fs[fs[pos[pos.size()-1]].to[i]].name==x&&now_op>=fs[fs[pos[pos.size()-1]].to[i]].op){
					pos.push_back(fs[pos[pos.size()-1]].to[i]);
				}
			}
		}
		if(s=="cut"&&now_op>=1){
			return 0;
		}
		if(s=="dir"){
			for(int i=0;i<fs[pos[pos.size()-1]].to.size();i++){
				if(fs[fs[pos[pos.size()-1]].to[i]].name!=""&&fs[fs[pos[pos.size()-1]].to[i]].op<=now_op)
					cout<<"FLODER:	"<<fs[fs[pos[pos.size()-1]].to[i]].name<<endl;
			}
			for(int i=0;i<fs[pos[pos.size()-1]].to.size();i++){
				if(f[fs[pos[pos.size()-1]].to[i]].l!=""&&f[fs[pos[pos.size()-1]].to[i]].op<=now_op)
					cout<<"FILE:	"<<f[fs[pos[pos.size()-1]].to[i]].l<<"."<<
					f[fs[pos[pos.size()-1]].to[i]].r<<endl;
			}
			for(int i=0;i<fs[pos[pos.size()-1]].to.size();i++){
				if(e[fs[pos[pos.size()-1]].to[i]].name!=""&&e[fs[pos[pos.size()-1]].to[i]].op<=now_op)
					cout<<"EXE_FILE:"<<e[fs[pos[pos.size()-1]].to[i]].name<<endl;
			}
		}
		if(s=="new_file"){
			string s;
			IN(s,exe_);
			f[next].l=s.substr(0,s.find('.'));
			f[next].r=s.substr(s.find('.')+1,s.size());
			f[next].op=now_op;
			fs[pos[pos.size()-1]].to.push_back(next);
			next++;
			all_file++;
		}
		if(s=="del_file"){
			string s;
			IN(s,exe_);
			string fl=s.substr(0,s.find('.'));
			string fr=s.substr(s.find('.')+1,s.size());
			for(int i=0;i<fs[pos[pos.size()-1]].to.size();i++){
				if(f[fs[pos[pos.size()-1]].to[i]].l==fl&&
					f[fs[pos[pos.size()-1]].to[i]].r==fr&&f[fs[pos[pos.size()-1]].to[i]].op<=now_op){
						f[fs[pos[pos.size()-1]].to[i]].l="";
						f[fs[pos[pos.size()-1]].to[i]].r="";
						f[fs[pos[pos.size()-1]].to[i]].data.clear();
					}
			}
			all_file--;
		}
		if(s=="power"){
			break;
		}
		if(s=="new_folder"||s=="new_files"){
			IN(fs[next].name,exe_);
			fs[next].op=now_op;
			fs[pos[pos.size()-1]].to.push_back(next);
			next++;
			all_file++;
		}
		if(s=="new_exe"){
//			cout<<next<<" "<<all_file<<endl;
			IN(e[next].name,exe_);
			fs[pos[pos.size()-1]].to.push_back(next);
//			cout<<e[next].data.size()<<endl;
			e[next].op=now_op;
			while(true){
				string x;
				IN(x,exe_);
				if(x=="\\")break;
				e[next].data.push_back(x);
//				cout<<x<<endl;
			}
			next++;
			all_file++;
//			cout<<e[next].data.size()<<endl;
//			output();
		}
		if(s=="res_start_name"&&now_op==1){
			string t;
			IN(t,exe_);
			start=t;
		}
		if(s=="del_folder"||s=="del_files"){
			string s;
			IN(s,exe_);
			for(int i=0;i<fs[pos[pos.size()-1]].to.size();i++){
				if(fs[fs[pos[pos.size()-1]].to[i]].name==s&&fs[fs[pos[pos.size()-1]].to[i]].op<=now_op){
						fs[fs[pos[pos.size()-1]].to[i]].name="";
						fs[fs[pos[pos.size()-1]].to[i]].to.clear();
					}
			}
			all_file--;
		}
		if(s=="del_exe"){
			string s;
			IN(s,exe_);
			for(int i=0;i<fs[pos[pos.size()-1]].to.size();i++){
				if(e[fs[pos[pos.size()-1]].to[i]].name==s&&e[fs[pos[pos.size()-1]].to[i]].op<=now_op){
						e[fs[pos[pos.size()-1]].to[i]].name="";
						e[fs[pos[pos.size()-1]].to[i]].data.clear();
					}
			}
			all_file--;
		}
		if(s=="res_name"){
			string s;
			IN(s,exe_);
			if(pos.size()!=1&&fs[pos[pos.size()-1]].op<=now_op)fs[pos[pos.size()-1]].name=s;
			else{
				if(s.size()==2&&s[1]==':'&&'A'<=s[0]&&s[0]<='Z'&&fs[pos[pos.size()-1]].op<=now_op)fs[pos[pos.size()-1]].name=s;
			}
		}
		if(s=="res_file_name"){
			string s,x;
			IN(s,exe_);
			IN(x,exe_);
			string fl=s.substr(0,s.find('.'));
			string fr=s.substr(s.find('.')+1,s.size());
			string fl2=x.substr(0,x.find('.'));
			string fr2=x.substr(x.find('.')+1,x.size());
			for(int i=0;i<fs[pos[pos.size()-1]].to.size();i++){
				if(f[fs[pos[pos.size()-1]].to[i]].l==fl&&
					f[fs[pos[pos.size()-1]].to[i]].r==fr&&f[fs[pos[pos.size()-1]].to[i]].op<=now_op){
						f[fs[pos[pos.size()-1]].to[i]].l=fl2;
						f[fs[pos[pos.size()-1]].to[i]].r=fr2;
					}
			}
		}
		if(s=="res_exe_name"){
			string s,x;
			IN(s,exe_);
			IN(x,exe_);
			for(int i=0;i<fs[pos[pos.size()-1]].to.size();i++){
				if(e[fs[pos[pos.size()-1]].to[i]].name==s&&e[fs[pos[pos.size()-1]].to[i]].op<=now_op){
						e[fs[pos[pos.size()-1]].to[i]].name=x;
					}
			}
		}
		if(s=="res"){
			next=2;
			all_file=1;
			f[1].l="";
			f[1].r="";
			f[1].op=0;
			f[1].data.clear();
			fs[1].name="C:";
			fs[1].op=0;
			fs[1].to.clear();
			break; 
		}
		if(s=="cls"){
			system("cls");
		}
		if(s=="@echo"){
			string s;
			IN(s,exe_);
			if(s=="on")l=1;
			else l=0;
		}
//		if(s=="video"){
//			cout<<"THIS VIDEO IS PLAY BY BOWEN VIDEO PLAYER.\n";
//			system("video.exe");
//		}
		if(s=="runif"){
			string s,r;
			IN(s,exe_);
			IN(r,exe_);
			bool x=0;
			for(int i=0;i<fs[pos[pos.size()-1]].to.size();i++){
				if(fs[fs[pos[pos.size()-1]].to[i]].name==s&&fs[fs[pos[pos.size()-1]].to[i]].op<=now_op){
						x=1;
					}
			}
			if(x){
				int x=-1;
				for(int i=0;i<fs[pos[pos.size()-1]].to.size();i++){
					if(e[fs[pos[pos.size()-1]].to[i]].name==r&&e[fs[pos[pos.size()-1]].to[i]].op<=now_op){
						x=fs[pos[pos.size()-1]].to[i];
					}
	//				cout<<e[fs[pos[pos.size()-1]].to[i]].name<<endl;
				}
				if(x!=-1){
					exe_=x;
					EXE.push_back(x);
					POS.push_back(0);
					now=0;
				}
			}
		} 
		if(s=="echo"){
			string x;
			IN(x,exe_);
			cout<<x<<endl;
		}
		if(s=="break"&&exe_!=0){
			EXE.pop_back();
			POS.pop_back();
			exe_=EXE[EXE.size()-1];
			now=POS[POS.size()-1]+1;
			cout<<"Return_ok"<<endl;
		}
		if(s=="return"&&exe_!=0){
			string s;
			IN(s,exe_);
			EXE.pop_back();
			POS.pop_back();
			exe_=EXE[EXE.size()-1];
			now=POS[POS.size()-1]+1;
			cout<<"Return_error:"<<s<<endl;
		}
		if(s=="run"){
			string s;
//			cin>>s;
			IN(s,exe_);
			int x=-1;
			for(int i=0;i<fs[pos[pos.size()-1]].to.size();i++){
				if(e[fs[pos[pos.size()-1]].to[i]].name==s&&e[fs[pos[pos.size()-1]].to[i]].op<=now_op){
					x=fs[pos[pos.size()-1]].to[i];
				}
//				cout<<e[fs[pos[pos.size()-1]].to[i]].name<<endl;
			}
			if(x!=-1){
				exe_=x;
				EXE.push_back(x);
				POS.push_back(0);
				now=0;
			}
//			cout<<x<<endl;
		}
		if(s=="open"){
			string s;
			IN(s,exe_);
			string fl=s.substr(0,s.find('.'));
			string fr=s.substr(s.find('.')+1,s.size());
			int now=0;
			for(int i=0;i<fs[pos[pos.size()-1]].to.size();i++){
				if(f[fs[pos[pos.size()-1]].to[i]].l==fl&&
					f[fs[pos[pos.size()-1]].to[i]].r==fr&&f[fs[pos[pos.size()-1]].to[i]].op<=now_op){
						now=fs[pos[pos.size()-1]].to[i];
					}
			}
			if(now!=0)for(int i=0;i<f[now].data.size();i++){
				cout<<f[now].data[i]<<endl;
			}
		}
		if(s=="res_file"){
			string s;
			IN(s,exe_);
			string fl=s.substr(0,s.find('.'));
			string fr=s.substr(s.find('.')+1,s.size());
			for(int i=0;i<fs[pos[pos.size()-1]].to.size();i++){
				if(f[fs[pos[pos.size()-1]].to[i]].l==fl&&
					f[fs[pos[pos.size()-1]].to[i]].r==fr&&f[fs[pos[pos.size()-1]].to[i]].op<=now_op){
						f[fs[pos[pos.size()-1]].to[i]].data.clear();
					}
			}
		}
		if(s=="set_file_cmd"){
			string s;
			IN(s,exe_);
			string fl=s.substr(0,s.find('.'));
			string fr=s.substr(s.find('.')+1,s.size());
			int now=0;
			for(int i=0;i<fs[pos[pos.size()-1]].to.size();i++){
				if(f[fs[pos[pos.size()-1]].to[i]].l==fl&&
					f[fs[pos[pos.size()-1]].to[i]].r==fr&&f[fs[pos[pos.size()-1]].to[i]].op<=now_op){
						now=fs[pos[pos.size()-1]].to[i];
					}
			}
			cin>>s;
			string t="";
			for(int i=0;i<s.size();i++){
				if(s[i]=='`')t+=" ";
				else t+=s[i];
			}
			f[now].data.push_back(t);
		}
		if(s=="set_file"){
			string s;
			IN(s,exe_);
			string fl=s.substr(0,s.find('.'));
			string fr=s.substr(s.find('.')+1,s.size());
			int now=0;
			for(int i=0;i<fs[pos[pos.size()-1]].to.size();i++){
				if(f[fs[pos[pos.size()-1]].to[i]].l==fl&&
					f[fs[pos[pos.size()-1]].to[i]].r==fr&&f[fs[pos[pos.size()-1]].to[i]].op<=now_op){
						now=fs[pos[pos.size()-1]].to[i];
					}
			}
			for(int i=1;1;i++){
				IN(s,exe_);
				if(s=="`")break;
				string t="";
				for(int i=0;i<s.size();i++){
					if(s[i]=='`')t+=" ";
					else t+=s[i];
				}
				f[now].data.push_back(t);
			}
		}
		if(s=="help"){
			cout<<	"HELP 命令指南\n";
			cout<<	"1.fa			去父亲[]\n";
			cout<<	"2.to			去子目录[*]\n";
			cout<<	"3.dir			打印当前目录的所有文件（夹）[]\n";
			cout<<	"4.new_file		新建文件[*.* *]\n";
			cout<<	"5.del_file		删除文件[*.*]\n";
			cout<<	"6.power			关机[]\n";
			cout<<	"7.new_folder		新建文件夹[*]\n";
			cout<<	"8.new_exe		新建可执行文件[* * * ... * \\]\n";
			cout<<	"9.del_folder		删除文件夹[*]\n";
			cout<<	"10.del_exe		删除可执行文件[*]\n";
			cout<<	"11.res_name		重命名此文件夹[*]\n";
			cout<<	"12.res_file_name	重命名文件[*.* *.*]\n";
			cout<<	"13.res_exe_name		重命名可执行文件[* *]\n";
			cout<<	"14.res			恢复出厂设置（此命令会自动关机）[]\n";
			cout<<	"15.cls			清屏[]\n";
			cout<<	"16.@echo		打开或关闭回显[on|off]\n";
			cout<<	"17.run_if		如果存在文件夹则运行程序[* *]\n";
			cout<<	"18.echo			输出[*]\n";
			cout<<	"19.break		退出程序（此命令在程序里才有用）[]\n";
			cout<<	"19.return		退出程序（此命令在程序里才有用）[*]\n";
			cout<<	"20.run			运行程序[*]\n";
			cout<<	"21.open			打开文件[*]\n";
			cout<<	"22.res_file		重置文件[*]\n";
			cout<<	"23.set_file		设置文件[* * ... *]\n"; 
			cout<<	"24.help			帮助[]\n";
			cout<<	"25.run_if		如果存在文件夹则运行程序[*]\n";
			cout<<	"26.get			拿权限[*]\n";
			cout<<	"27.draw 		画图[不可用]\n";
			cout<<	"28.cut 			断电\n";
			cout<<	"29.check 		是否为管理员\n";
			cout<<	"30.res_file_name 	更改启动程序名称\n";
			cout<<	"31.set_file_cmd 	用命令行格式输入文件[*]\n";
			cout<<	"32.run_same		如果文件相等则运行程序[* *][不可用]\n";
			cout<<	"32.version		版本\n";
		}
		if(s=="draw"){
			system("start .\\draw.exe");
		}
		if(s=="check"){
			if(now_op==0)cout<<"users";
			else cout<<"admin";
			cout<<endl;
		} 
		if(s=="run_same"){
		} 
		if(s=="get"){
			IN(s,exe_);
			if(s=="users") now_op=0;
			if(s=="admin"){
				if(exe_==0){
					cout<<"system want to have admin operator.\n";
				}
				else{
					cout<<"exe:"<<e[exe_].name<<" want to have admin operator.\n";
				}
				cout<<"Do you want?(N/Y/G)(N=no Y=yes G=give more data)";
				char c;
				cin>>c;
				if(c=='Y')now_op=1;
				if(c=='G'){
					if(exe_==0){
						cout<<"This is system(Doesn't you want that?).\n";
					}
					else{
						cout<<"This is exe\n";
						cout<<"Where: ";
						cout<<"root";
						for(int i=1;i<pos.size();i++){
							cout<<"\\"<<fs[pos[i]].name;
						}
						cout<<endl;
					}
					cout<<"Do you want?(N/Y)(N=no Y=yes)";
					cin>>c;
					if(c=='Y'){
						now_op=1;
					}
				}
			}
		}
		if(s=="cmd"){
			system("start .\\main.exe");
		}
		if(s=="version"){
			cout<<"4.0.1"<<endl;
		} 
//		cout<<s<<endl;
		int x=POS[POS.size()-1];
		POS.pop_back();
		POS.push_back(x+1);
//		for(int i=0;i<POS.size();i++){
//			cout<<POS[i]<<" ";
//		}
//		cout<<endl;
//		for(int i=0;i<EXE.size();i++){
//			cout<<EXE[i]<<" ";
//		}
//		cout<<endl;
//		system("pause");
	}
	output();
	return 0;
}
