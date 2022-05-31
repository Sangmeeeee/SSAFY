#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;
	map<string, int> parkingTime;       // 차량 번호, 총 주차 시간
	map<string, string> inoutInfo;  // 차량 번호, 입차 시간

	for (int r = 0; r < records.size(); r++) {
		// records[r]에서 정보를 추출한다.
		string time = records[r].substr(0, 5);
		string carNumber = records[r].substr(6, 4);
		string inout = records[r].substr(11, records[r].length() - 1);

		if (inout == "IN") {
			// 만약 입차했다면 inoutInfo에 입차 시간을 삽입한다.
			inoutInfo[carNumber] = time;
		}
		else if (inout == "OUT") {
			// 만약 출차했다면 inoutInfo에서 차량 번호를 찾아 주차 시간을 계산한다.
			int iHour = stoi(inoutInfo[carNumber].substr(0, 2));
			int iMin = stoi(inoutInfo[carNumber].substr(3, 2));
			int oHour = stoi(time.substr(0, 2));
			int oMin = stoi(time.substr(3, 2));

			int total = oHour * 60 + oMin - iHour * 60 - iMin;
			// 이미 주차된 적이 있다면 feeInfo에 주차 시간을 더해주고,
			// 처음 주차한 거라면 주차 시간을 삽입한다.
			if (parkingTime[carNumber] > 0)
				parkingTime[carNumber] += total;
			else {
				parkingTime[carNumber] = total;
			}

			// inoutInfo에서 입차 시간을 초기화해준다.
			inoutInfo[carNumber] = "";
		}
	}

	// 만약 inoutInfo에 아직 입차 시간이 남아있다면, 23:59에 출차한 것으로 간주한다.
	for (auto iter = inoutInfo.begin(); iter != inoutInfo.end(); iter++) {
		if (iter->second != "") {
			int hour = stoi(inoutInfo[iter->first].substr(0, 2));
			int min = stoi(inoutInfo[iter->first].substr(3, 2));
			int total = 23 * 60 + 59 - hour * 60 - min;

			if (parkingTime[iter->first] > 0)
				parkingTime[iter->first] += total;
			else
				parkingTime[iter->first] = total;
		}
	}

	// parkingTime에 저장된 정보(차량 번호, 총 주차 시간)를 바탕으로 주차 요금을 계산한다.
	for (auto iter = parkingTime.begin(); iter != parkingTime.end(); iter++) {
		int time = parkingTime[iter->first];
		// 기본 시간보다 작다면 주차 요금은 기본 요금만 낸다.
		int fee = 0;
		if (time < fees[0]) {
			fee = fees[1];
		}
		else {
			fee = fees[1];
			time -= fees[0];
			if (time%fees[2] == 0)
				fee += (time / fees[2]) * fees[3];
			else
				fee += ((time / fees[2]) * fees[3]) + fees[3];
		}
		answer.push_back(fee);
	}

	return answer;
}