class Abstract_Game_State
{
public:
    Abstract_Game_State(/* args */);
    ~Abstract_Game_State();

    virtual void update() = 0;

private:
    /* data */
};
