# Mô hình chung đệ quy
void Try( input ) {
    if (< Kich_Thuoc_Dau_Vao_Du_Nho >) {
        do <Buoc_Co_So >
        // Tra_Ve_KQ_Truong_Hop_Co_So
    } else { // Buoc de qui
        foreach (< Bai_Toan_Con_Trong_CTDQ >)
        call Try( new_input );
        Combine (< Loi_Giai_Cac_Bai_Toan_Con >);
    return solution ;
    }
}

# Mô hình chung quay lui
void Try( int i) {
    foreach (< Ung_Vien_Duoc_Chap_Nhan_c >) {
        Update (< Cac_Bien_Trang_Thai >);
        x[i] <-- c;
        if (i==n) <Ghi_Nhan_Mot_Loi_Giai > ;
        else Try(i +1);
        < Tra_Cac_Bien_Ve_Trang_Thai_Cu >;
    }
}