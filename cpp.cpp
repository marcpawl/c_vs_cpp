const std::string s = "*A";
const std::string t = "*A\n";
 
std::string::size_type n = 0;
while ( ( n = chartDataString.find( s, n ) ) != std::string::npos )
{
    chartDataString.replace( n, s.size(), t );
    n += t.size();
}
