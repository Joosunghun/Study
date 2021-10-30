<<<<<<< HEAD
// 3_2 Å« ¼öÀÇ ¹ýÄ¢
// N°³ ÀÚ¿¬¼ö, M¹ø ´õÇÏ´Âµ¥ K ¸¸Å­¸¸ ¿¬¼ÓÇØ¼­ ´õÇØÁú ¼ö ÀÖÀ½
=======
// 3_1 í° ìˆ˜ì˜ ë²•ì¹™
// Nê°œ ìžì—°ìˆ˜, Më²ˆ ë”í•˜ëŠ”ë° K ë§Œí¼ë§Œ ì—°ì†í•´ì„œ ë”í•´ì§ˆ ìˆ˜ ìžˆìŒ
>>>>>>> d91d49590df568eabc8f0a53fffddf02a5b06acf

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int i, n, m, k;
	vector<int> arr;
	int result = 0;
	int count = 0;
	cin >> n >> m >> k;

<<<<<<< HEAD
	for (i = 0; i < n; i++) {                                // n °³ÀÇ ¼ö¸¦ arr¿¡ ³Ö±â
=======
	for (i = 0; i < n; i++) {                                // n ê°œì˜ ìˆ˜ë¥¼ arrì— ë„£ê¸°
>>>>>>> d91d49590df568eabc8f0a53fffddf02a5b06acf
		int x;
		cin >> x;
		arr.push_back(x);
	}

<<<<<<< HEAD
	sort(arr.begin(), arr.end());                      // Á¤·Ä
	int first = arr[n - 1];                                 // °¡Àå Å« ¼ö
	int second = arr[n - 2];                           // µÎ ¹øÂ°·Î Å«¼ö

	count = (m / (k + 1)) * k;                         // °¡Àå Å« ¼ö°¡ ´õÇØÁö´Â È½¼ö °è»ê
	count += m % (k + 1);

	result += count * first;                             // °¡Àå Å« ¼ö ´õÇÏ±â
	result += (m - count) * second;               // µÎ ¹øÂ°·Î Å« ¼ö ´õÇÏ±â
=======
	sort(arr.begin(), arr.end());                      // ì •ë ¬
	int first = arr[n - 1];                                 // ê°€ìž¥ í° ìˆ˜
	int second = arr[n - 2];                           // ë‘ ë²ˆì§¸ë¡œ í°ìˆ˜

	count = (m / (k + 1)) * k;                         // ê°€ìž¥ í° ìˆ˜ê°€ ë”í•´ì§€ëŠ” íšŸìˆ˜ ê³„ì‚°
	count += m % (k + 1);

	result += count * first;                             // ê°€ìž¥ í° ìˆ˜ ë”í•˜ê¸°
	result += (m - count) * second;               // ë‘ ë²ˆì§¸ë¡œ í° ìˆ˜ ë”í•˜ê¸°
>>>>>>> d91d49590df568eabc8f0a53fffddf02a5b06acf

	cout << result << endl;
	
}
