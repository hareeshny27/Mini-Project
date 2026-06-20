/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.javafx_projects;

/**
 *
 * @author KGCAS
 */
import java.util.Scanner;

class Product {
    int id;
    String name;
    double price;
    int stock;

    Product(int id, String name, double price, int stock) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.stock = stock;
    }

    void display() {
        System.out.println(id + ". " + name + 
            " | Price: " + price + 
            " | Stock: " + stock);
    }
}

public class RetailShopMenu {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Product[] products = {
            new Product(1, "Soap", 30, 50),
            new Product(2, "Shampoo", 120, 30),
            new Product(3, "Rice", 60, 100),
            new Product(4, "Milk", 25, 40)
        };

        double totalBill = 0;
        int choice;

        do {
            System.out.println("\n===== MENU =====");
            System.out.println("1. View Products");
            System.out.println("2. Buy Product");
            System.out.println("3. Generate Bill & Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {

                case 1:
                    System.out.println("\n--- Product List ---");
                    for (Product p : products) {
                        p.display();
                    }
                    break;

                case 2:
                    System.out.print("Enter Product ID: ");
                    int pid = sc.nextInt();

                    Product selected = null;
                    for (Product p : products) {
                        if (p.id == pid) {
                            selected = p;
                            break;
                        }
                    }

                    if (selected == null) {
                        System.out.println("Invalid product!");
                        break;
                    }

                    System.out.print("Enter Quantity: ");
                    int qty = sc.nextInt();

                    if (qty > selected.stock) {
                        System.out.println("Out of stock!");
                    } else {
                        double cost = qty * selected.price;
                        totalBill += cost;
                        selected.stock -= qty;

                        System.out.println("Added: " + selected.name);
                        System.out.println("Cost: " + cost);
                    }
                    break;

                case 3:
                    double gst = totalBill * 0.05;
                    double finalBill = totalBill + gst;

                    System.out.println("\n------ FINAL BILL ------");
                    System.out.println("Total: " + totalBill);
                    System.out.println("GST: " + gst);
                    System.out.println("Final Amount: " + finalBill);
                    System.out.println("Thank You!");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 3);

        sc.close();
    }
}
