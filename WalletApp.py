class WalletUser:
    def __init__(self, username, password):
        self.username = username
        self.password = password
        self.balance = 0.0
        self.transactions = []

def create_user():
    print("Entrez un nom d'utilisateur : ")
    username = input().strip()

    print("Entrez un mot de passe : ")
    password = input().strip()

    global current_user
    current_user = WalletUser(username, password)
    print("Compte créé avec succès !")

def login_user():
    print("Entrez le nom d'utilisateur : ")
    username = input().strip()

    print("Entrez le mot de passe : ")
    password = input().strip()

    global current_user
    if username == current_user.username and password == current_user.password:
        print("Connexion réussie !")
        show_main_menu()
    else:
        print("Identifiants incorrects. Veuillez réessayer.")

def show_main_menu():
    while True:
        print("\nMenu Principal :")
        print("1. Afficher le Solde")
        print("2. Historique des Transactions")
        print("3. Déposer de l'Argent")
        print("4. Retirer de l'Argent")
        print("5. Transférer de l'Argent")
        print("6. Se Déconnecter")

        choice = input("Entrez votre choix : ").strip()

        if choice == "1":
            display_balance()
        elif choice == "2":
            show_transaction_history()
        elif choice == "3":
            deposit_money()
        elif choice == "4":
            withdraw_money()
        elif choice == "5":
            transfer_money()
        elif choice == "6":
            print("Déconnexion...")
            global current_user
            current_user = None
            break
        else:
            print("Choix invalide. Veuillez réessayer.")

def display_balance():
    print(f"Solde actuel : ${current_user.balance:.2f}")

def show_transaction_history():
    print("Historique des transactions :")
    for transaction in current_user.transactions:
        print(transaction)

def deposit_money():
    amount = float(input("Entrez le montant à déposer : "))
    current_user.balance += amount
    current_user.transactions.append(f"Dépôt de ${amount:.2f}")
    print("Dépôt réussi !")

def withdraw_money():
    amount = float(input("Entrez le montant à retirer : "))
    if current_user.balance >= amount:
        current_user.balance -= amount
        current_user.transactions.append(f"Retrait de ${amount:.2f}")
        print("Retrait réussi !")
    else:
        print("Solde insuffisant.")

def transfer_money():
    recipient = input("Entrez le nom d'utilisateur du destinataire : ").strip()
    amount = float(input("Entrez le montant à transférer : "))
    if current_user.balance >= amount:
        current_user.balance -= amount
        current_user.transactions.append(f"Transfert de ${amount:.2f} à {recipient}")
        print("Transfert réussi !")
    else:
        print("Solde insuffisant.")

while True:
    print("1. Créer un Compte")
    print("2. Se Connecter")
    print("3. Quitter")

    choice = input("Entrez votre choix : ").strip()

    if choice == "1":
        create_user()
    elif choice == "2":
        login_user()
    elif choice == "3":
        print("Au revoir !")
        break
    else:
        print("Choix invalide. Veuillez réessayer.")
