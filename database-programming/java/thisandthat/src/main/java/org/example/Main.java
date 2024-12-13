package org.example;

import thisandthatAR.ArticleAR;
import thisandthatDAO.*;

import java.sql.SQLException;
import java.util.List;

public class Main {
    public static void main(String[] args) throws SQLException {
        new ConnectionFactory("jdbc:mysql://localhost/thisandthat", "root", "parola");
        ArticleAR article = new ArticleAR();

        article.find(3005);
        System.out.println(article.getArticleName() + article.getCurrency() + " " + article.getPrice());

        article.setPrice(56.26F);
        article.save();
        System.out.println(article.getArticleName() + article.getCurrency() + " " + article.getPrice());


        ArticleAR newArt = new ArticleAR();
        newArt.find(9059);
        System.out.println(newArt.getArticleName() + " " + newArt.getCurrency() + " " + newArt.getPrice());
//        newArt.delete();
//        System.out.println(newArt.getArticleName() + newArt.getCurrency() + " " + newArt.getPrice());


        // ----------- ARTICLEGROUP TABLE STUFF
        ArticleGroupBO group = new ArticleGroupBO();
        List<ArticleGroup> allGroups = group.getAllArticleGroups();
        System.out.println("\n------- FETCHING ALL ARTICLE GROUPS -------");
        for (ArticleGroup group1 : allGroups) {
            System.out.print(group1.getArticleGroupId() + ": " + group1.getArticleGroupName() + "  ");
        }

        System.out.println("\n------- FETCHING ARTICLES BELONGING TO A GROUP ID -------");
        List<Article> a_list = group.getArticleGroup(3).getArticles();
        for (Article art : a_list) {
            System.out.printf("--> %s ", art.getArticleName());
        }

        System.out.println("\n------- FETCHING ALL ARTICLES --------");
        ArticleBO articol = new ArticleBO();
        for (Article art : articol.getAllArticle()) {
            System.out.printf("--> %d: %s ", art.getArticle_Id(), art.getArticleName());
        }
        System.out.println();

        // --------- GET ARTICLE GROUPS  -------------
//        Article newArticle = articol.getArticle(9058);
//        List<ArticleGroup> articleGrps = newArticle.getArticleGroups(newArticle.getArticle_Id());
//        System.out.println(articleGrps);

        // INSERT NEW ARTICLEGROUP
//        ArticleGroup pp = new ArticleGroup();
//        pp.setArticleGroupName("Peripherals");
//        ArticleGroupBO peripherals = new ArticleGroupBO();
//        peripherals.addArticleGroup(pp);

        // DELETE ARTICLEGROUP
//        group.deleteArticleGroup(group.getArticleGroup(20));
//
//        for (ArticleGroup group1 : allGroups) {
//            System.out.print(group1.getArticleGroupId() + ": " + group1.getArticleGroupName() + "  ");
//        }

    }
}