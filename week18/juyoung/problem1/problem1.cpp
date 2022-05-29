#include <string>
#include <vector>
#include <cctype>
#include <tuple>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(tuple<string, int, string> t1, tuple<string, int, string> t2) {
	if (get<0>(t1) == get<0>(t2)) 
		return get<1>(t1) < get<1>(t2);
	return get<0>(t1) < get<0>(t2);
}

vector<string> solution(vector<string> files) {
	vector<string> answer;
	vector<tuple<string, int, string>> split;	// head, number, filename

	for (int v = 0; v < (int)files.size(); v++) {
		string filename = files[v];
		int idx = 0;
		string temp = "";
		string head = "";
		int number = 0;

		while (idx < filename.length()) {
			if ('0' <= filename[idx] && filename[idx] <= '9') {
				head = temp;
				temp = "";
				for (int i = idx; i < filename.length(); i++) {
					if ('0' <= filename[i] && filename[i] <= '9')
						temp += filename[i];
					else {
						idx = i;
						break;
					}
				}
				number = stoi(temp);
				break;
			}
			temp += tolower(filename[idx]);
			idx++;
		}

		split.push_back({ head, number, filename });
	}

	stable_sort(split.begin(), split.end(), compare);
	for (int i = 0; i < (int)split.size(); i++)
		answer.push_back(get<2>(split[i]));

	return answer;
}

int main() {
	int n;
	string temp;
	vector<string> files;
	vector<string> answer;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		files.push_back(temp);
	}

	/*files.push_back("F-5 Freedom Fighter");
	files.push_back("B-50 Superfortress");
	files.push_back("A-10 Thunderbolt II");
	files.push_back("F-14 Tomcat");*/

	answer = solution(files);
	for (int i = 0; i < (int)answer.size(); i++)
		cout << answer[i] << " ";
	return 0;
 }

/*
6
img12.png
img10.png
img02.png
img1.png
IMG01.GIF
img2.JPG

files.push_back("F-5 Freedom Fighter");
files.push_back("B-50 Superfortress");
files.push_back("A-10 Thunderbolt II");
files.push_back("F-14 Tomcat");

4
muzi1.png1
MUZI1.png2
MUZI1.png3
muzi1.png4
*/