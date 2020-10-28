Sub main()

    'r1 is an Excel sheet range of cells
    Dim r1 As Range
    Set r1 = Range("A2:C4")
    
    'Add a stop before function returning and add watch to M
    result = CholeskyDecomposition(r1)
    
End Sub


Function CholeskyDecomposition(ByVal r As Object) As Variant

    Dim a() As Double
    Dim M() As Double
    Dim i As Integer, j As Integer, n As Integer, h As Integer
    Dim U As Double
    
    ' number of columns in input correlation matrix R
    n = r.Columns.Count
        
    ReDim a(1 To n, 1 To n)
    ReDim M(1 To n, 1 To n)
    
    For i = 1 To n
        For j = 1 To n
            a(i, j) = r(i, j)
            M(i, j) = 0
            If i = j Then
                M(i, j) = 1
            End If
        Next
    Next
    
    For i = 1 To n
        For j = 1 To n
            U = a(i, j)
            For h = 1 To (i - 1)
                U = U - M(i, h) * M(j, h)
            Next
            If j = i Then
                M(i, i) = Sqr(U)
            Else
                M(j, i) = U / M(i, i)
            End If
        Next
    Next

    CholeskyDecomposition = M
    
End Function
