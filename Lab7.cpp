/****************************************************
* Автор: Алексеев Д.К.                              *
* Дата: 22.10.2024                                  *
* Название: Лаба 7 Работа с файлами                 *
****************************************************/
#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

struct Product {
    string name;
    string country;
    string supplier;
    int deliveryTime;
    int quantity;
};

vector<Product> readProductsFromFile(const string& filename) {
    ifstream file(filename);
    vector<Product> products;

    if (file.is_open()) {
        Product product;
        
        while (file >> product.name >> product.country >> product.supplier >> product.deliveryTime >> product.quantity) {
            products.push_back(product);
        }
        file.close();
    } else {
        cout << "Не удалось открыть файл" << endl;
    }

    return products;
}

void printProducts(const vector<Product>& products) {
    for (const auto& product : products) {
        cout << "Товар: " << product.name << ", Страна: " << product.country << ", Фирма: " << product.supplier << ", Срок доставки: " 
             << product.deliveryTime << " месяцев, Объем партии: " 
             << product.quantity << " кг" << endl;
    }
}

void findProductInfo(const vector<Product>& products, const string& productName) {
    bool found = false;
    int totalDeliveryTime = 0;
    int totalQuantity = 0;
    int maxQuantity = 0;
    string supplierWithMaxQuantity;

    for (const auto& product : products) {
        if (product.name == productName) {
            cout << "Страна: " << product.country << ", Фирма: " << product.supplier << endl;
            found = true;
            totalDeliveryTime += product.deliveryTime;
            totalQuantity += product.quantity;

            if (product.quantity > maxQuantity) {
                maxQuantity = product.quantity;
                supplierWithMaxQuantity = product.supplier;
            }
        }
    }

    if (found) {
        cout << "Общий срок доставки: " << totalDeliveryTime << " месяцев" << endl;
        cout << "Общий объем поставок: " << totalQuantity << " кг" << endl;
        cout << "Фирма-поставщик с наибольшим объемом партии: " << supplierWithMaxQuantity << endl;
    } else {
        cout << "Товар не найден." << endl;
    }
}

int main() {
    string filename = "products.txt";
    vector<Product> products = readProductsFromFile(filename);
    
    printProducts(products);

    string productName;
    cout << "Введите наименование товара для поиска: ";
    cin >> productName;

    findProductInfo(products, productName);

    return 0;
}