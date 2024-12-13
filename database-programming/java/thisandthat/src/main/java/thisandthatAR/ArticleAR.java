package thisandthatAR;

import thisandthatDAO.ConnectionFactory;

import java.sql.*;
import java.util.List;

public class ArticleAR {

    private Statement st;
    private Connection connection;
    private PreparedStatement pst;

    private int article_Id;
    private String articleName;
    private float price;
    private String currency;
    private boolean deleted;
    private List articleGroups;

    /**
     * @param artikel_Id the artikel_Id to set
     */
    public void setArtikel_Id(int id) {
        this.article_Id = id;
    }

    /**
     * @return the artikel_Id
     */
    public int getArticle_Id() {
        return article_Id;
    }

    /**
     * @param einzelpreis the einzelpreis to set
     */
    public void setPrice(float price) {
        this.price = price;
    }

    /**
     * @return the einzelpreis
     */
    public float getPrice() {
        return price;
    }

    /**
     * @param waehrung the waehrung to set
     */
    public void setCurrency(String cur) {
        this.currency = cur;
    }

    /**
     * @return the waehrung
     */
    public String getCurrency() {
        return currency;
    }

    /**
     * @param deleted the deleted to set
     */
    public void setDeleted(boolean deleted) {
        this.deleted = deleted;
    }

    /**
     * @return the deleted
     */
    public boolean isDeleted() {
        return deleted;
    }

    /**
     * @param bezeichnung the bezeichnung to set
     */
    public void setArticleName(String name) {
        this.articleName = name;
    }

    /**
     * @return the bezeichnung
     */
    public String getArticleName() {
        return articleName;
    }

    /**
     * @param warengruppen the warengruppen to set
     */
    public void setArticleGroups(List groups) {
        this.articleGroups = groups;
    }

    /**
     * @return the warengruppen
     */
    public List getArticleGroups() {
        return articleGroups;
    }

    /**
     * used for loading from database
     */
    public void find(int article_Id) {
        String query = "SELECT ARTICLE_ID, ARTICLE, PRICE, CURRENCY, DELETED FROM ARTICLE WHERE article_Id = ?";
        try {
            connection = ConnectionFactory.getConnection();
            pst = connection.prepareStatement(query);
            pst.setInt(1, article_Id);
            ResultSet rs = pst.executeQuery();

            if (rs.next()) {
                this.article_Id = rs.getInt("article_id");
                this.articleName = rs.getString("article");
                this.price = rs.getFloat("price");
                this.currency = rs.getString("currency");
                this.deleted = rs.getBoolean("deleted");
            }

            rs.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    /**
     * used for creation or update in database
     */
    public void save() {
        String query;
        try {
            connection = ConnectionFactory.getConnection();
            if (this.getArticle_Id() == 0) {
                query = "INSERT INTO ARTICLE (ARTICLE, PRICE, CURRENCY, DELETED) VALUES (?, ?, ?, ?)";
                System.out.println("Inserting new article...");
            } else {
                query = "UPDATE ARTICLE SET ARTICLE = ?, PRICE = ?, CURRENCY = ?, DELETED = ? WHERE ARTICLE_ID = ?";
                System.out.println("Article with ID exists in our database, performing update...");
            }
            pst = connection.prepareStatement(query);

            pst.setString(1, this.getArticleName());
            pst.setFloat(2, this.getPrice());
            pst.setString(3, this.getCurrency());
            pst.setBoolean(4, this.isDeleted());

            if (this.getArticle_Id() != 0) {
                pst.setInt(5, this.getArticle_Id());
            }

            pst.executeUpdate();
            connection.commit();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    /**
     * used for deletion in database
     */
    public void delete() {
        String query = "DELETE FROM ARTICLE WHERE ARTICLE_ID = ?";
        try {
            connection = ConnectionFactory.getConnection();
            pst = connection.prepareStatement(query);
            pst.setInt(1, this.getArticle_Id());
            int rowsAffected = pst.executeUpdate();

            if (rowsAffected != 0) {
                System.out.println("Article with ID " + this.getArticle_Id() + " was deleted.");
                connection.commit();
            } else {
                System.out.println("Article couldn't be deleted, make sure the ID is valid.");
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}
