## FrequencyDictionary (Частотный словарь) on C++
### Представляю реализацию частотного словаря на c++.
- Алгоритмическая оценка работы программы: Пусть **m - количество символов в тексте; n - количество слов в тексте**, получаемая сложность `O(m + n*log(n)*log(m))`
- Настроен CI для прогона тестов при коммите
- Универсальная сборка через докер для любой системы: `docker build -t frequency_dictionary .`
- После сборки запуск происходит такой командой docker `docker run --rm -v $(pwd)/data:/app/data frequency_dictionary /app/data/input.txt /app/data/output.txt`
