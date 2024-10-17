def get_string(prompt):
    return input(prompt)


text = get_string("text: ")

counter_letter = 0
counter_words = 0
counter_sentences = 0

for char in text:
    if char.isalpha():
        counter_letter += 1

counter_words = len(text.split())

counter_sentences = text.count('.') + text.count('!') + text.count('?')

L = (counter_letter / counter_words) * 100
S = (counter_sentences / counter_words) * 100
index = 0.0588 * L - 0.296 * S - 15.8

if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {int(round(index))}")
