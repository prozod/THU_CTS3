package thisandthatDAO;

import java.util.List;

public interface ArticleGroupDAO {
    public List<ArticleGroup> getAllArticleGroups();

    public ArticleGroup getArticleGroup(int id);

    public void addArticleGroup(ArticleGroup ag);

    public void deleteArticleGroup(ArticleGroup articleGroup);
}
