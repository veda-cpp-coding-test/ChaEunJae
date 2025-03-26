// 백준 문제 : 일곱 난쟁이 (빠질 2명의 난쟁이 고르는 방식도 가능)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int dwarf[9];
	for(int i=0;i<9;i++){
		cin >> dwarf[i];
	}
	
	vector<int> dwarf_7;
	int sum = 0;
	for(int a=0;a<=2;a++){
		sum += dwarf[a];
		for(int b=a+1;b<=3;b++){
			sum += dwarf[b];
			for(int c=b+1;c<=4;c++){
				sum += dwarf[c];
				for(int d=c+1;d<=5;d++){
					sum += dwarf[d];
					for(int e=d+1;e<=6;e++){
						sum += dwarf[e];
						for(int f=e+1;f<=7;f++){
							sum += dwarf[f];
							for(int g=f+1;g<=8;g++){
								sum += dwarf[g];
								// cout << dwarf[a] << " " << dwarf[b] << " " << dwarf[c] << " " << dwarf[d] << " " << dwarf[e] << " " << dwarf[f] << " " << dwarf[g] << "  sum : " << sum << "\n";
								if(sum == 100){
									dwarf_7.push_back(dwarf[a]);
									dwarf_7.push_back(dwarf[b]);
									dwarf_7.push_back(dwarf[c]);
									dwarf_7.push_back(dwarf[d]);
									dwarf_7.push_back(dwarf[e]);
									dwarf_7.push_back(dwarf[f]);
									dwarf_7.push_back(dwarf[g]);
									stable_sort(dwarf_7.begin(),dwarf_7.end());
									
									for(auto i:dwarf_7){
										cout << i << "\n";
									}
									return 0;
								}
								sum -= dwarf[g];
							}
							sum -= dwarf[f];
						}
						sum -= dwarf[e];
					}
					sum -= dwarf[d];
				}
				sum -= dwarf[c];
			}
			sum -= dwarf[b];
		}
		sum -= dwarf[a];
	}
	
}
