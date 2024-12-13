package org.example;

import thisandthat.*;

import java.util.List;

public class Main {
    public static void main(String[] args) {
        CustomerService customerService = new CustomerService();
        List<Customer> customers = customerService.getAllCustomers();
        for (Customer customer : customers) {
            System.out.println(customer);
        }
        customerService.close();


        ArticleService articleService = new ArticleService();
        for (Article article : articleService.getArticles()) {
            System.out.println(article);
        }
        articleService.close();

        SupplierService supplierService = new SupplierService();
        for (Supplier supplier : supplierService.getSuppliers()) {
            System.out.println(supplier);
        }
        supplierService.close();

        ArticleGroupService articleGroupService = new ArticleGroupService();
        for (ArticleGroup ag : articleGroupService.getArticleGroups()) {
            System.out.println(ag);
        }
        articleGroupService.close();
    }

}