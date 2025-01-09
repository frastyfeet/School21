## Contents :book:
   1. [Готовый докер](#part-1-готовый-докер) 
   2. [Операции с контейнером](#part-2-операции-с-контейнером) 
   3. [Мини веб-сервер](#part-3-мини-веб-сервер) 
   4. [Свой докер](#part-4-свой-докер) 
   5. [Dockle](#part-5-dockle) 
   6. [Базовый Docker Compose](#part-6-базовый-docker-compose)


![simple_docker](../misc/images/simple_docker.png)

## Part 1. Готовый докер

   **== Задание ==**

   ##### Возьми официальный докер-образ с **nginx** и выкачай его при помощи `docker pull`.

   ![alt text](images/image.png)
   ##### Проверь наличие докер-образа через `docker images`.

   ![alt text](images/image-1.png)
   ##### Запусти докер-образ через `docker run -d [image_id|repository]`.
   ![alt text](images/image-2.png)
   ##### Проверь, что образ запустился через `docker ps`.
   ![alt text](images/image-3.png)
   ##### Посмотри информацию о контейнере через `docker inspect [container_id|container_name]`.
   ![alt text](images/image-4.png)
   ##### По выводу команды определи и помести в отчёт размер контейнера, список замапленных портов и ip контейнера.
   - размер контейнера
   ![alt text](images/image-5.png)
   - список замапленных портов
   ![alt text](images/image-6.png)
   - ip контейнера
   ![alt text](images/image-7.png)
   ##### Останови докер контейнер через `docker stop [container_id|container_name]`.
   ![alt text](images/image-8.png)
   ##### Проверь, что контейнер остановился через `docker ps`.
   ![alt text](images/image-9.png)
   ##### Запусти докер с портами 80 и 443 в контейнере, замапленными на такие же порты на локальной машине, через команду *run*.

   ![alt text](images/image-10.png)
   ![alt text](images/image-14.png)


   ##### Проверь, что в браузере по адресу *localhost:80* доступна стартовая страница **nginx**.

   ![alt text](images/image-11.png)
   ##### Перезапусти докер контейнер через `docker restart [container_id|container_name]`.

   ![alt text](images/image-12.png)

   ##### Проверь любым способом, что контейнер запустился.

   ![alt text](images/image-13.png)


## Part 2. Операции с контейнером

   **== Задание ==**

   ##### Прочитай конфигурационный файл *nginx.conf* внутри докер контейнера через команду *exec*.

   ![alt text](images/image-15.png)

   ##### Создай на локальной машине файл *nginx.conf*.

   ![alt text](images/image-16.png)

   ##### Настрой в нем по пути */status* отдачу страницы статуса сервера **nginx**.

   ![alt text](images/image-18.png)

   ##### Скопируй созданный файл *nginx.conf* внутрь докер-образа через команду `docker cp`.

   ![alt text](images/image-19.png)

   ##### Перезапусти **nginx** внутри докер-образа через команду *exec*.

   ![alt text](images/image-20.png)

   ##### Проверь, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**.

   ![alt text](images/image-17.png)


   ##### Экспортируй контейнер в файл *container.tar* через команду *export*.

   ![alt text](images/image-21.png)

   ##### Останови контейнер.

   ![alt text](images/image-22.png)

   ##### Удали образ через `docker rmi [image_id|repository]`, не удаляя перед этим контейнеры.

   ![alt text](images/image-23.png)



   ##### Удали остановленный контейнер.

   ![alt text](images/image-24.png)


   ##### Импортируй контейнер обратно через команду *import*.

   ![alt text](images/image-25.png)

   ##### Запусти импортированный контейнер.

   ![alt text](images/image-26.png)

   ##### Проверь, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**.

   ![alt text](images/image-27.png)


## Part 3. Мини веб-сервер


   **== Задание ==**

   ##### Напиши мини-сервер на **C** и **FastCgi**, который будет возвращать простейшую страничку с надписью `Hello World!`.

   ![alt text](images/image-28.png)

   ##### Запусти написанный мини-сервер через *spawn-fcgi* на порту 8080.


   ![alt text](images/image-29.png)


   ##### Напиши свой *nginx.conf*, который будет проксировать все запросы с 81 порта на *127.0.0.1:8080*.

   ![alt text](images/image-30.png)

   ##### Проверь, что в браузере по *localhost:81* отдается написанная тобой страничка.

   ![alt text](images/image-31.png)

   ##### Положи файл *nginx.conf* по пути *./nginx/nginx.conf* (это понадобится позже).

   ![alt text](images/image-32.png)


## Part 4. Свой докер

   **== Задание ==**

   #### Напиши свой докер-образ, который:
   ##### 1) собирает исходники мини сервера на FastCgi из [Части 3](#part-3-мини-веб-сервер);
   ![alt text](images/image228.png)
   ##### 2) запускает его на 8080 порту;
   ![alt text](images/image-220.png)
   ##### 3) копирует внутрь образа написанный *./nginx/nginx.conf*;
   ##### 4) запускает **nginx**.
   ![alt text](images/image-110.png)

   ##### Собери написанный докер-образ через `docker build` при этом указав имя и тег.

   ![alt text](images/image-33.png)

   ##### Проверь через `docker images`, что все собралось корректно.
   ![alt text](images/image-44.png)
   ##### Запусти собранный докер-образ с маппингом 81 порта на 80 на локальной машине и маппингом папки *./nginx* внутрь контейнера по адресу, где лежат конфигурационные файлы **nginx**'а (см. [Часть 2](#part-2-операции-с-контейнером)).

   ![alt text](images/image-55.png)


   ##### Проверь, что по localhost:80 доступна страничка написанного мини сервера.

   ![alt text](images/image-66.png)

   ##### Допиши в *./nginx/nginx.conf* проксирование странички */status*, по которой надо отдавать статус сервера **nginx**.

   ![alt text](images/image-77.png)

   ##### Перезапусти докер-образ.

   ![alt text](images/image-88.png)
   *Если всё сделано верно, то, после сохранения файла и перезапуска контейнера, конфигурационный файл внутри докер-образа должен обновиться самостоятельно без лишних действий*
   ##### Проверь, что теперь по *localhost:80/status* отдается страничка со статусом **nginx**

   ![alt text](images/image-99.png)


## Part 5. **Dockle**

   **== Задание ==**

   ##### Просканируй образ из предыдущего задания через `dockle [image_id|repository]`.


   ![alt text](images/image6-.png)

   ##### Исправь образ так, чтобы при проверке через **dockle** не было ошибок и предупреждений.


   ![alt text](images/image6-1.png)

   **исправленный вариант**

   ![alt text](images/image6-2.png)

## Part 6. Базовый **Docker Compose**

**== Задание ==**

##### Напиши файл *docker-compose.yml*, с помощью которого:
##### 1) Подними докер-контейнер из [Части 5](#part-5-инструмент-dockle) _(он должен работать в локальной сети, т.е. не нужно использовать инструкцию **EXPOSE** и мапить порты на локальную машину)_.
##### 2) Подними докер-контейнер с **nginx**, который будет проксировать все запросы с 8080 порта на 81 порт первого контейнера.
##### Замапь 8080 порт второго контейнера на 80 порт локальной машины.

![alt text](images/image6-3.png)

##### Останови все запущенные контейнеры.

![alt text](images/image6-4.png)

##### Собери и запусти проект с помощью команд `docker-compose build` и 
`docker-compose up`.

![alt text](images/image6-5.png)


![alt text](images/image6-6.png)

![alt text](images/image6-7.png)

##### Проверь, что в браузере по *localhost:80* отдается написанная тобой страничка, как и ранее.

![alt text](images/image6-8.png)