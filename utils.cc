int z_abs(int x) {
    if (x >= 0) return x;
    return (-x);
}

int z_gcd(int x, int y) {
    int remainder;
    x = z_abs(x);
    y = z_abs(y);
    while (y != 0) {
        remainder = x % y;
        x = y;
        y = remainder;
    }
    return x;
}

int z_lcm(int x, int y) {
    if (x == 0 || y == 0) return 0; // they cannot be zero
    int abs_x = z_abs(x);
    int abs_y = z_abs(y);
    return (abs_x / z_gcd(abs_x, abs_y)) * abs_y;
}