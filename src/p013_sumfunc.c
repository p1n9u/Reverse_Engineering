#include <windows.h>
#include <stdio.h>

int sum(int a, int b) {
	return a+b;
}


/*
 * original disassembly
 * mov eax, dword ptr ss:[esp+8]
 * mov ecx, dword ptr ss:[esp+4]
 * add eax, ecx
 * retn
 */

/*
 * __declspec(naked)
 * naked : 함수 안에서 부수적인 코드를 생성하지 않는 옵션, 컴파일러는 이 함수안에서 어떤 자체적인 코드도 생성하지 않게됨
 * 따라서 naked 함수를 만들기 위해 개발자가 스택이나 변수 할당, 레지스터 사용 등의 모든 처리 내용을 작성해야 함
 * 순수 어셈블리로 만들어진 코드를 작성할 때 많이 사용
 */

__declspec(naked) sumAsm(int a, int b) {
	__asm {
		mov ebx, dword ptr ss:[esp+8]
		mov edx, dword ptr ss:[esp+4]
		add edx, ebx
		mov eax, edx
		retn
	}
}

int main(void) {
	int x = sum(3,4);
	printf("x : %d\n", x);

	int y = sumAsm(3,4);
	printf("y : %d\n", y);

	return 0;
}
