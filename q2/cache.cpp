#include <bits/stdc++.h>
using namespace std;
class processor {
   public:
    string table[2][3];
    /*column names : Coherency State, Address Tag, Data
	Row names : B0, B1*/
};
main() {
    processor P[4][2];
    //Adding Data into Processors according to given Data Set
    //P0,0
    P[0][0].table[0][0] = "M";    P[0][0].table[0][1] = "100";    P[0][0].table[0][2] = "0010";
    P[0][0].table[1][0] = "S";    P[0][0].table[1][1] = "108";    P[0][0].table[1][2] = "0008";

    //P0,1
    P[0][1].table[0][0] = "M";    P[0][1].table[0][1] = "130";    P[0][1].table[0][2] = "0068";
    P[0][1].table[1][0] = "S";    P[0][1].table[1][1] = "118";    P[0][1].table[1][2] = "0018";

    //P1,0
    P[1][0].table[0][0] = "S";    P[1][0].table[0][1] = "130";    P[1][0].table[0][2] = "0068";
    P[1][0].table[1][0] = "S";    P[1][0].table[1][1] = "118";    P[1][0].table[1][2] = "0018";

    //P1,1
    P[1][1].table[0][0] = "M";    P[1][1].table[0][1] = "126";    P[1][1].table[0][2] = "0010";
    P[1][1].table[1][0] = "I";    P[1][1].table[1][1] = "132";    P[1][1].table[1][2] = "0026";

    //P2,0
    P[2][0].table[0][0] = "M";    P[2][0].table[0][1] = "122";    P[2][0].table[0][2] = "0043";
    P[2][0].table[1][0] = "M";    P[2][0].table[1][1] = "142";    P[2][0].table[1][2] = "0032";

    //P2,1
    P[2][1].table[0][0] = "M";    P[2][1].table[0][1] = "147";    P[2][1].table[0][2] = "0040";
    P[2][1].table[1][0] = "I";    P[2][1].table[1][1] = "153";    P[2][1].table[1][2] = "0029";

    //P3,0
    P[3][0].table[0][0] = "M";    P[3][0].table[0][1] = "149";    P[3][0].table[0][2] = "0063";
    P[3][0].table[1][0] = "M";    P[3][0].table[1][1] = "156";    P[3][0].table[1][2] = "0073";

    //P3,1
    P[3][1].table[0][0] = "S";    P[3][1].table[0][1] = "120";    P[3][1].table[0][2] = "0020";
    P[3][1].table[1][0] = "S";    P[3][1].table[1][1] = "108";    P[3][1].table[1][2] = "0008";

    //Instruction Input
    int proc_num, chip_num;
    cout << "Enter Processor Number and Chip Number : ";
    cin >> proc_num >> chip_num;
    string inst, addr, val;
    cout << "Enter Instruction(Read/Write)  :  ";
    cin >> inst;
    
    if (inst == "Write"){
		cout << "Address and Value :  ";
		cin >> addr;
        cin >> val;
	}

    if (P[proc_num][chip_num].table[0][1] == addr) {
        cout << inst << " Hit" << endl;
        if (inst == "Write") {
            if (P[proc_num][chip_num].table[0][0] == "S") {
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 2; j++) {
                        if (i == proc_num && j == chip_num)
                            continue;
                        if (P[i][j].table[0][1] == addr || P[i][j].table[1][1] == addr) {
                            cout << "Invalidate sent to P" << i << "," << j << endl;
                        }
                    }
                }
            }
        }
    } else if (P[proc_num][chip_num].table[1][1] == addr) {
        cout << inst << " Hit" << endl;
        if (inst == "Write") {
            if (P[proc_num][chip_num].table[1][0] == "S") {
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 2; j++) {
                        if (i == proc_num && j == chip_num)
                            continue;
                        if (P[i][j].table[0][1] == addr || P[i][j].table[1][1] == addr) {
                            cout << "Invalidate sent to P" << i << "," << j << endl;
                        }
                    }
                }
            }
        }
    } else {
        cout << inst << " miss" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                if (i == proc_num && j == chip_num)
                    continue;
                if (P[i][j].table[0][1] == addr || P[i][j].table[1][1] == addr) {
                    cout << "Invalidate sent to P" << i << "," << j << endl;
                }
            }
        }
    }
}
