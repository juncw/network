#include <iostream>
#include <string>
using namespace std;

const int MAX_NETWORK_SIZE = 100;
int main(void) {

	// m(行), n(列)
	int m = 0, n = 0;
	// strNodeBridge 连接桥
	string strNodeBridge = "";

	cin >> m >> n;
	cin >> strNodeBridge;

	// 网络大小和输入桥的合法性检查
	if ( m < 0 || n < 0 || (m == 0 && n == 0) ) {
		cout << "Number out of range.";
		return -1;
	}
	// 申请空间和初始化
	int** network = new int*[2 * m + 1];
	for (int i = 0; i < (2 * m + 1); ++i) {
		network[i] = new int[2 * n + 1];
	}
	for (int i = 0; i < (2 * m + 1); ++i) {
		for (int j = 0; j < (2 * n + 1); ++j) {
			// 初始化为墙
			network[i][j] = 0;
		}
	}

	int startX = 0, startY = 0, endX = 0, endY = 0;
	string strSelectNode = "";    // 选取节点临时变量
	bool isStartCell = false;
	for (int i = 0; i < strNodeBridge.length(); ++i) {
		if (strNodeBridge[i] == ',' && !isStartCell) {  // startX
			isStartCell = true;
			int j = 0;
			while (strSelectNode[j] != '\0') {
				if (strSelectNode[j] >= '0' && strSelectNode[j] <= '9') {

				}
				else {
					cout << "Invalidnumber format." << endl;
					return -1;
				}
			}
		}else if (strNodeBridge[i] == ' ') {   // startY

		}else if (strNodeBridge[i] == ';' || strNodeBridge[i+1] == '\0') {   // endY
			int j = 0;
			while (strSelectNode[j] != '\0') {
				if (strSelectNode[j] >= '0' && strSelectNode[j] <= '9') {

				}
				else {
					cout << "Invalid number format." << endl;
					return -1;
				}
			}

			if (startX < 0 || startY < 0 || endX < 0 || endY < 0) {
				cout << "Number out of range." << endl;
				return -1;
			}
			else {
				// network连接
				if(){
					cout << "Incorrect command format." << endl;
					return -1;
				}else {
					// network赋值
				}
			}

		}else if (strNodeBridge[i] == ',' && !isStartCell) {    // startY
			isStartCell = false;
			int j = 0;
			while (strSelectNode[j] != '\0') {
				if (strSelectNode[j] >= '0' && strSelectNode[j] <= '9') {

				}
				else {
					cout << "Invalidnumber format." << endl;
					return -1;
				}
			}
		}
	}

	return 0;
}