package org.example;

import java.util.Scanner;

public class Main {
    private static WalletUser currentUser;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("1. Création de Compte");
            System.out.println("2. Connexion");
            System.out.println("3. Quitter");

            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    createUser(scanner);
                    break;
                case 2:
                    loginUser(scanner);
                    break;
                case 3:
                    System.out.println("Au revoir !");
                    System.exit(0);
                    break;
                default:
                    System.out.println("Choix invalide. Veuillez réessayer.");
            }
        }



    }

    private static void createUser(Scanner scanner) {
        System.out.println("Entrez un nom d'utilisateur : ");
        String username = scanner.next();

        System.out.println("Entrez un mot de passe : ");
        String password = scanner.next();

        currentUser = new WalletUser(username, password);
        System.out.println("Compte créé avec succès !");
    }

    private static void loginUser(Scanner scanner) {
        System.out.println("Entrez le nom d'utilisateur : ");
        String username = scanner.next();

        System.out.println("Entrez le mot de passe : ");
        String password = scanner.next();

        if (currentUser.username.equals(username) && currentUser.password.equals(password)) {
            currentUser = new WalletUser(username, password);
            System.out.println("Connexion réussie !");
            showMainMenu(scanner);
        } else {
            System.out.println("Identifiants incorrects. Veuillez réessayer.");
        }
    }

    private static void showMainMenu(Scanner scanner) {
        while (true) {
            System.out.println("\nMenu Principal : ");
            System.out.println("1. Affichage du Solde");
            System.out.println("2. Historique des Transactions");
            System.out.println("3. Dépôt d'Argent");
            System.out.println("4. Retrait d'Argent");
            System.out.println("5. Transfert d'Argent");
            System.out.println("6. Déconnexion");

            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    displayBalance();
                    break;
                case 2:
                    showTransactionHistory();
                    break;
                case 3:
                    depositMoney(scanner);
                    break;
                case 4:
                    withdrawMoney(scanner);
                    break;
                case 5:
                    transferMoney(scanner);
                    break;
                case 6:
                    System.out.println("Déconnexion...");
                    currentUser = null;
                    return;
                default:
                    System.out.println("Choix invalide. Veuillez réessayer.");
            }
        }
    }

    private static void displayBalance() {
        System.out.println("Solde actuel : $" + currentUser.balance);
    }

    private static void showTransactionHistory() {
        System.out.println("Historique des transactions : ");
        for (String transaction : currentUser.transactions) {
            System.out.println(transaction);
        }
    }

    private static void depositMoney(Scanner scanner) {
        System.out.println("Entrez le montant à déposer : ");
        double amount = scanner.nextDouble();
        currentUser.balance += amount;
        currentUser.transactions.add("Dépôt de $" + amount);
        System.out.println("Dépôt réussi !");
    }

    private static void withdrawMoney(Scanner scanner) {
        System.out.println("Entrez le montant à retirer : ");
        double amount = scanner.nextDouble();
        if (currentUser.balance >= amount) {
            currentUser.balance -= amount;
            currentUser.transactions.add("Retrait de $" + amount);
            System.out.println("Retrait réussi !");
        } else {
            System.out.println("Solde insuffisant.");
        }
    }

    private static void transferMoney(Scanner scanner) {
        System.out.println("Entrez le nom d'utilisateur du destinataire : ");
        String recipient = scanner.next();

        System.out.println("Entrez le montant à transférer : ");
        double amount = scanner.nextDouble();

        if (currentUser.balance >= amount) {
            currentUser.balance -= amount;
            currentUser.transactions.add("Transfert de $" + amount + " à " + recipient);
            System.out.println("Transfert réussi !");
        } else {
            System.out.println("Solde insuffisant.");
        }
    }



}