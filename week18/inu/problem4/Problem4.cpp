#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

vector<string> split(string s, char delimeter) {
    vector<string> splitted;
    stringstream input(s);
    string temp;
    while (getline(input, temp, delimeter)) {
        splitted.push_back(temp);
    }
    return splitted;
}

int getParkingTime(string start, string end) {
    int shour = stoi(start.substr(0, 2));
    int smin = stoi(start.substr(3, 2));
    int ehour = stoi(end.substr(0, 2));
    int emin = stoi(end.substr(3, 2));
    return ehour * 60 + emin - shour * 60 - smin;
}

int getCharge(vector<int> fees, int time) {
    int charge = fees[1];
    if (time > fees[0]){
        int remain = (time - fees[0]) / fees[2];
        if ((time - fees[0]) % fees[2] != 0) remain++;
        charge += remain * fees[3];
    }
    return charge;
}

// fees: 기본시간, 기본요금, 단위시간, 단위요금
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<string, string> inout;
    unordered_map<string, int> time;
    set<string> car_number;

    for (string s : records) {
        vector<string> record = split(s, ' ');

        // IN이면 inout에 넣기
        if (!record[2].compare("IN")) {
            inout[record[1]] = record[0];
            if (car_number.find(record[1]) == car_number.end()) {
                time[record[1]] = 0;
                car_number.insert(record[1]);
            }
        }
        // OUT이면 주차시간 구하고 inout에서 삭제
        else {
            int parkingTime = getParkingTime(inout[record[1]], record[0]);
            time[record[1]] += parkingTime;
            inout.erase(record[1]);
        }
    }
    // inout에 남은 차량들 주차시간 구하기
    for (auto i : inout) {
        int parkingTime = getParkingTime(i.second, "23:59");
        time[i.first] += parkingTime;
    }
    // 차량번호순으로 주차요금 구하기
    for (string s : car_number) {
        int charge = getCharge(fees, time[s]);
        answer.push_back(charge);
    }

    return answer;
}

int main() {
    vector<int> fees1 = { 180, 5000, 10, 600 };
    vector<int> fees2 = { 120, 0, 60, 591 };
    vector<int> fees3 = { 1, 461, 1, 10 };

    vector<string> records1 = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };
    vector<string> records2 = { "16:00 3961 IN","16:00 0202 IN","18:00 3961 OUT","18:00 0202 OUT","23:58 3961 IN" };
    vector<string> records3 = { "00:00 1234 IN" };

    vector<int> answer1 = solution(fees1, records1);
    vector<int> answer2 = solution(fees2, records2);
    vector<int> answer3 = solution(fees3, records3);
}