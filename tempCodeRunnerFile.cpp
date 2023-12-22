bool readFromFile(char *FileName, char arr[], const int MAX_SIZE) {
    ifstream File;   // Создали поток ввода для чтения данных из файла
    File.open (FileName);  // Открыли файл
    if (!File.is_open())  //  Проверили удалось ли открыть файл
    {
        cout << "Открыть файл не удалось! \n" ;
        return 0;   // Файл не открыт
    }
    while (!File.eof()) // Читаем все строки из файла и выводим их на экран
    {
        File.getline (arr, MAX_SIZE, '.');
        cout << arr << endl;
    }
    File.close();  // Закрываем файл
    return 1;
}