#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MonsterWorld.h"
#include "Human.h"
#include "VariousMonsters.h"
#include "RankingBoard.h"
using namespace std;

int main() {
    RankingBoard rank;
    try {
        rank.load("MonsterWorld.rnk");
    } catch (FileException e) {
        string passwd, correct = "123456";
        cout << "<관리자 비밀번호를 입력하세요>: ";
        cin >> passwd;

        if (passwd != correct) {
            cout << "비밀번호가 맞지 않습니다. 프로그램 종료...\n\n";
            return 0;
        }

        string savefile;
        cout << "랭킹을 저장할 새 파일명을 입력하세요: ";
        cin >> savefile;

        try {
            rank.store(savefile);
            cout << "랭킹이 성공적으로 저장되었습니다.\n";
        } catch (FileException e) {
            cout << "랭킹 저장 중 오류 발생: " << e.filename << "\n";
        }
        return 0;
    }

    rank.print("게임 랭킹 : 시작");

    srand((unsigned int)time(NULL));
    int w = 16, h = 8;

    MonsterWorld game(w, h);
    game.add(new Zombie("엄청한좀비", "S", rand() % w, rand() % h));
    game.add(new Vampire("뱀파이어여왕", "*", rand() % w, rand() % h));
    game.add(new KGhost("어쩌다귀신", "♥", rand() % w, rand() % h));
    game.add(new Jiangshi("못먹어도고", "ㅎ", rand() % w, rand() % h, true));
    game.add(new Jiangshi("못먹어세로", "ㅎ", rand() % w, rand() % h, false));

    Human* human = new Human("미래의인류", "Ω", rand() % w, rand() % h);
    game.add(human);
    game.play(500, 10);

    cout << "<------ 게임 종료 ------>\n";

    rank.add(human->nItem, human->nItem / human->total);
    rank.print("게임 랭킹 : 종료");

    try {
        rank.store("MonsterWorld.rnk");
    } catch (FileException e) {
        cout << "기본 랭킹 저장 중 오류 발생: " << e.filename << "\n";
    }

    return 0;
}
