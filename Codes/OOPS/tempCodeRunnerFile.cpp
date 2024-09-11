 abc(const abc &obj)
    {
        x = obj.x;
        y = new int(*obj.y);
    }