import streamlit as st
import pandas as pd


def read_csv(file_name):
    df = pd.read_csv(file_name)
    return df


def get_val(val):
    table_1_data = read_csv('table1.csv')
    table_1_data.set_index('Index #', inplace=True)
    value = table_1_data.loc[val, 'Value']
    return value


def get_table_2_val():

    alpha = int(get_val('A5') + get_val('A20'))
    beta = int(get_val('A15') / get_val('A7'))
    charlie = int(get_val('A13') * get_val('A12'))

    table_2_data = {
        "Category": ["Alpha", "Beta", "Charlie"],
        "Value": [alpha, beta, charlie]
    }

    return table_2_data


st.title("Assignment (Mulah Tech)")
table1 = read_csv('table1.csv')
st.table(table1)

table2 = get_table_2_val()
st.title('Table 2')
st.table(table2)
