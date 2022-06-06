#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;
	map<string, int> parkingTime;       // ���� ��ȣ, �� ���� �ð�
	map<string, string> inoutInfo;  // ���� ��ȣ, ���� �ð�

	for (int r = 0; r < records.size(); r++) {
		// records[r]���� ������ �����Ѵ�.
		string time = records[r].substr(0, 5);
		string carNumber = records[r].substr(6, 4);
		string inout = records[r].substr(11, records[r].length() - 1);

		if (inout == "IN") {
			// ���� �����ߴٸ� inoutInfo�� ���� �ð��� �����Ѵ�.
			inoutInfo[carNumber] = time;
		}
		else if (inout == "OUT") {
			// ���� �����ߴٸ� inoutInfo���� ���� ��ȣ�� ã�� ���� �ð��� ����Ѵ�.
			int iHour = stoi(inoutInfo[carNumber].substr(0, 2));
			int iMin = stoi(inoutInfo[carNumber].substr(3, 2));
			int oHour = stoi(time.substr(0, 2));
			int oMin = stoi(time.substr(3, 2));

			int total = oHour * 60 + oMin - iHour * 60 - iMin;
			// �̹� ������ ���� �ִٸ� feeInfo�� ���� �ð��� �����ְ�,
			// ó�� ������ �Ŷ�� ���� �ð��� �����Ѵ�.
			if (parkingTime[carNumber] > 0)
				parkingTime[carNumber] += total;
			else {
				parkingTime[carNumber] = total;
			}

			// inoutInfo���� ���� �ð��� �ʱ�ȭ���ش�.
			inoutInfo[carNumber] = "";
		}
	}

	// ���� inoutInfo�� ���� ���� �ð��� �����ִٸ�, 23:59�� ������ ������ �����Ѵ�.
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

	// parkingTime�� ����� ����(���� ��ȣ, �� ���� �ð�)�� �������� ���� ����� ����Ѵ�.
	for (auto iter = parkingTime.begin(); iter != parkingTime.end(); iter++) {
		int time = parkingTime[iter->first];
		// �⺻ �ð����� �۴ٸ� ���� ����� �⺻ ��ݸ� ����.
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