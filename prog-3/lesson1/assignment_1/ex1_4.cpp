/*
class CA
{
  public:
    int ia1;

  private:
    int ia2;
    void ma1()
    {
      ia1 = 10;
    }

  public:
    void ma2(CA obj)
    {
      obj.ia1 = 20;
      ia2 = obj.ia2;
    }
};

class CB
{
  private:
    CA *obja;

  public:
    CB()
    {
      obja = new CA();
    }

    void mb()
    {
      obja->ia1 = 11;
      obja->ia2 = 22;
      obja->ma1();
      obja->ma2(*obja);
    }
};
*/

// Class CB is wrong because we are instantiating a new CA object inside then
// trying to access its private members and methods (ia2 and ma1();).
