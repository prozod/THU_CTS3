from thisandthat import Article, SpecialItem

article = Article()
article.set_article_name("Keyboard")
article.set_price(16.81)

special_item = SpecialItem(discount=20)
special_item.set_article_name("Christmas Tree")
special_item.set_price(25.20)

print(f"Article starts with 'k/K': {article.starts_with_k()}")

print(f"Article gross price: {article.get_gross_price():.2f}")

print(f"Special Item discount: {special_item.get_discount()}%")

print(f"Special Item gross price (20% discount): {special_item.get_gross_price():.2f}")
