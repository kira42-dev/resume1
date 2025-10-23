import tkinter as tk
from tkinter import messagebox


class TicTacToe:
    def __init__(self):
        self.window = tk.Tk()
        self.window.title("Крестики-нолики")
        self.window.geometry("400x450")
        self.window.resizable(False, False)

        self.current_player = "X"
        self.board = [""] * 9
        self.game_active = True

        self.create_widgets()

    def create_widgets(self):
        # Заголовок
        self.title_label = tk.Label(
            self.window,
            text="Крестики-Нолики",
            font=("Arial", 20, "bold"),
            fg="#2c3e50"
        )
        self.title_label.pack(pady=10)

        # Текущий игрок
        self.player_label = tk.Label(
            self.window,
            text=f"Сейчас ходит: {self.current_player}",
            font=("Arial", 14),
            fg="#e74c3c"
        )
        self.player_label.pack(pady=5)

        # Игровое поле
        self.frame = tk.Frame(self.window)
        self.frame.pack(pady=20)

        self.buttons = []
        for i in range(9):
            row = i // 3
            col = i % 3

            button = tk.Button(
                self.frame,
                text="",
                font=("Arial", 20, "bold"),
                width=5,
                height=2,
                bg="#ecf0f1",
                fg="#2c3e50",
                command=lambda idx=i: self.make_move(idx)
            )
            button.grid(row=row, column=col, padx=2, pady=2)
            self.buttons.append(button)

        # Кнопка сброса
        self.reset_button = tk.Button(
            self.window,
            text="Новая игра",
            font=("Arial", 14),
            bg="#3498db",
            fg="white",
            padx=20,
            pady=10,
            command=self.reset_game
        )
        self.reset_button.pack(pady=20)

    def make_move(self, position):
        if not self.game_active or self.board[position] != "":
            return

        self.board[position] = self.current_player
        self.buttons[position].config(
            text=self.current_player,
            fg="#e74c3c" if self.current_player == "X" else "#3498db"
        )

        if self.check_winner():
            self.game_active = False
            messagebox.showinfo("Победа!", f"Игрок {self.current_player} победил!")
            self.highlight_winning_line()
        elif "" not in self.board:
            self.game_active = False
            messagebox.showinfo("Ничья!", "Игра закончилась вничью!")
        else:
            self.current_player = "O" if self.current_player == "X" else "X"
            self.player_label.config(text=f"Сейчас ходит: {self.current_player}")

    def check_winner(self):
        # Выигрышные комбинации
        winning_combinations = [
            [0, 1, 2], [3, 4, 5], [6, 7, 8],  # Горизонтальные
            [0, 3, 6], [1, 4, 7], [2, 5, 8],  # Вертикальные
            [0, 4, 8], [2, 4, 6]  # Диагональные
        ]

        for combo in winning_combinations:
            if (self.board[combo[0]] == self.board[combo[1]] ==
                    self.board[combo[2]] == self.current_player):
                self.winning_combo = combo
                return True
        return False

    def highlight_winning_line(self):
        for position in self.winning_combo:
            self.buttons[position].config(bg="#2ecc71")

    def reset_game(self):
        self.current_player = "X"
        self.board = [""] * 9
        self.game_active = True

        self.player_label.config(text=f"Сейчас ходит: {self.current_player}")

        for button in self.buttons:
            button.config(text="", bg="#ecf0f1")

    def run(self):
        self.window.mainloop()


# Запуск игры
if __name__ == "__main__":
    game = TicTacToe()
    game.run()