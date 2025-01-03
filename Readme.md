## Приветствую!

Данный репозиторий посвящён решению задач по предмету "Программирование на ЭВМ", первого семестра первого курса Механики Мех-Мата МГУ.

## Содержание

В данном репозитории вы найдёте решения различных задач, представленных в [этой подборке](https://lectures.stargeo.ru/tasks/zadachiIadd2.pdf).

[📘 Wiki документация](https://github.com/AZEN-SGG/MSUStudentWork/wiki).

## Инструкции по Использованию

### Клонирование Репозитория

Чтобы начать работу с этим репозиторием, сначала клонируйте его на свой локальный компьютер:

```bash
git clone https://github.com/AZEN-SGG/MSUStudentWork.git
cd MSUStudentWork
```

### Редакция Makefile для Linux

Для удобной компиляции проектов на Linux, выполните следующие шаги:

1. Сделайте `makefile.sh` исполняемым:
    ```bash
    chmod +x makefile.sh
    ```
2. Запустите скрипт из корня проекта:
    ```bash
    ./makefile.sh
    ```
3. Убедитесь, что замены произошли, проверив любой Makefile:
    ```bash
    cat Sorting/7Ex/makefile
    ```

Этот скрипт автоматически настраивает Makefile для вашей системы, упрощая процесс компиляции и сборки проектов.

### Компиляция и Запуск Задач

После настройки Makefile, вы можете скомпилировать и запустить любую задачу следующим образом:

```bash
cd ПУТЬ_К_ЗАДАЧЕ
make
```

## Вклад и Обратная Связь

Если вы обнаружили ошибку или у вас есть предложения по улучшению, пожалуйста, создайте [issue](https://github.com/AZEN-SGG/MSUStudentWork/issues) или отправьте [pull request](https://github.com/AZEN-SGG/MSUStudentWork/pulls).

---

*Желаю успешного изучения и решения задач!*
