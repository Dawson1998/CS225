


vector<string> NoProblem(int start, vector<int> created, vector<int> needed) {

    // your code here
    vector<string> out;
    int current = start;
    for(size_t i = 0; i < created.size(); i++)
    {
        if(current >= needed[i])
            {out.push_back( "No problem! :D"); current -= needed[i];}
        else
            out.push_back("No problem. :(");
            current += created[i];
    }
    return out;
}
