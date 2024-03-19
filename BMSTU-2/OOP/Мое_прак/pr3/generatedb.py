import random
import sqlite3

# Списки с реальными названиями стадионов и футбольных команд
stadiums = ['Old Trafford', 'Camp Nou', 'Santiago Bernabeu', 'Allianz Arena', 'San Siro',
            'Emirates Stadium', 'Stamford Bridge', 'Anfield', 'Etihad Stadium', 'Signal Iduna Park']
teams = ['Manchester United', 'Barcelona', 'Real Madrid', 'Bayern Munich', 'AC Milan',
         'Arsenal', 'Chelsea', 'Liverpool', 'Manchester City', 'Borussia Dortmund']

# Создаем соединение с базой данных и курсор
conn = sqlite3.connect(
    '/Users/pluttan/Desktop/_Сем2/BMSTU-2/ООП/Мое_прак/pr3/pr3.db')
cursor = conn.cursor()

# Создаем таблицу с полями id, stadium, team1, team2, score1 и score2
cursor.execute(
    'CREATE TABLE IF NOT EXISTS games (id INTEGER PRIMARY KEY, stadium TEXT, team1 TEXT, team2 TEXT, score1 INTEGER, score2 INTEGER)')

# Заполняем таблицу 50 случайными записями
for i in range(50):
    stadium = random.choice(stadiums)
    team1 = random.choice(teams)
    team2 = random.choice(teams)
    # Избегаем случая, когда команды одинаковы
    while team1 == team2:
        team2 = random.choice(teams)
    score1 = random.randint(0, 5)
    score2 = random.randint(0, 5)
    # Вставляем запись в таблицу
    cursor.execute('INSERT INTO games (stadium, team1, team2, score1, score2) VALUES (?, ?, ?, ?, ?)',
                   (stadium, team1, team2, score1, score2))

# Сохраняем изменения и закрываем соединение с базой данных
conn.commit()
conn.close()
