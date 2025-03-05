#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int find_last_occurrence(const wchar_t *sentence, wchar_t ch) {
  int last_index = -1;
  int length = wcslen(sentence);

  for (int i = 0; i < length; i++) {
    if (sentence[i] == ch) {
      last_index = i;
    }
  }

  return last_index;
}

int main() {
  setlocale(LC_CTYPE,"");

  wchar_t sentence1[100], sentence2[100];
  wchar_t target_char = L'ш';

  wprintf(L"Введите первое предложение: ");
  if (fgetws(sentence1, sizeof(sentence1) / sizeof(wchar_t), stdin) == NULL) {
    wprintf(L"Ошибка при вводе первого предложения.\n");
    return 1;
  }

  wprintf(L"Введите второе предложение: ");
  if (fgetws(sentence2, sizeof(sentence2) / sizeof(wchar_t), stdin) == NULL) {
    wprintf(L"Ошибка при вводе второго предложения.\n");
    return 1;
  }

  int index1 = find_last_occurrence(sentence1, target_char);
  int index2 = find_last_occurrence(sentence2, target_char);

  if (index1 != -1 && index2 != -1) {
    if (index1 > index2) {
      wprintf(L"В первом предложении буква 'ш' имеет больший порядковый номер: "
              L"%d\n",
              index1 + 1);
    } else if (index2 > index1) {
      wprintf(L"Во втором предложении буква 'ш' имеет больший порядковый "
              L"номер: %d\n",
              index2 + 1);
    } else {
      wprintf(L"Последние вхождения буквы 'ш' в обоих предложениях имеют "
              L"одинаковый порядковый номер: %d\n",
              index1 + 1);
    }
  } else if (index1 != -1) {
    wprintf(L"Буква 'ш' найдена только в первом предложении: %d\n", index1 + 1);
  } else if (index2 != -1) {
    wprintf(L"Буква 'ш' найдена только во втором предложении: %d\n",
            index2 + 1);
  } else {
    wprintf(L"Буква 'ш' не найдена ни в одном предложении.\n");
  }

  return 0;
}