# Engine

## Базовый функционал
Имея класс `Subject` и его инстанс `subj`, необходимо завернуть метод `f3` класса `Subject` со списком аргументов для последующего вызова, передавая неограниченный словарь аргументов:

```cpp
Wrapper wrapper(&subj, &Subject::f3, {{"arg1", 0}, {"arg2", 0}});
Engine engine;
engine.register_command(&wrapper, "command1");  
std::cout << engine.execute("command1", { {"arg1", 4}, {"arg2", 5} }) << std::endl;
```

## Модификация текстового документа
Класс необходимо адаптировать для работы с текстовыми документами:
- Базовый тип аргументов: `string` (или поддержка полностью произвольных сигнатур)
- Поддерживаемые операции:

1. Замена слов  
2. Поиск словосочетаний  
3. Изменение первых букв слов на заглавные  
4. Изменение первой буквы предложения на заглавную  
5. Добавление последовательной нумерации к каждому предложению + начало с новой строки  

## Требования к реализации
- Поддержка инкапсуляции произвольных сигнатур методов  
- Четкое разделение между механизмом вызова и бизнес-логикой операций  
- Возможность легкого расширения набора 
