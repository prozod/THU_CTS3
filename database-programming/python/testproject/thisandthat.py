class Article:
  def __init__(self) -> None:
    self.__article_id = None
    self.__article_name = None
    self.__price = None
    self.__currency = None
    self.__deleted = None
    self.__article_group = []

  def __str__(self):
    return f"({self.__article_id}): {self.__article_name}, {self.__price}{self.__currency}"

  def get_article_id(self):
    return self.__article_id

  def set_article_id(self, value):
    self.__article_id = value

  def get_article_name(self):
    return self.__article_name

  def set_article_name(self, value):
    self.__article_name = value

  def get_price(self):
    return self.__price

  def set_price(self, value):
    self.__price = value

  def get_currency(self):
    return self.__currency

  def set_currency(self, value):
    self.__currency = value

  def get_deleted(self):
    return self.__deleted

  def set_deleted(self, value):
    self.__deleted = value


  def starts_with_k(self) -> bool:
        return self.__article_name.lower().startswith('k')

  def get_gross_price(self) -> float:
        vat_rate = 0.19
        gross_price = self.__price * (1 + vat_rate)
        return gross_price


class SpecialItem(Article):
    def __init__(self, discount: float = 0.0) -> None:
        super().__init__()
        self.__discount = discount

    def get_discount(self) -> float:
        return self.__discount

    def set_discount(self, discount: float) -> None:
        self.__discount = discount

    def get_gross_price(self) -> float: # this is an override in python like wtf
        vat_rate = 0.19
        net_price = self.get_price() * (1 - self.__discount / 100)
        gross_price = net_price * (1 + vat_rate)
        return gross_price
