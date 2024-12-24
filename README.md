<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ATM Machine Program</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            line-height: 1.6;
            background-color: #f4f4f9;
            color: #333;
            margin: 0;
            padding: 0;
        }
        header {
            background: #333;
            color: #fff;
            padding: 10px 0;
            text-align: center;
        }
        .container {
            max-width: 800px;
            margin: 20px auto;
            padding: 20px;
            background: #fff;
            border-radius: 5px;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
        }
        h1, h2, h3 {
            color: #333;
        }
        code {
            background: #f4f4f4;
            padding: 2px 5px;
            border-radius: 3px;
        }
        pre {
            background: #f4f4f4;
            padding: 10px;
            border-radius: 5px;
            overflow-x: auto;
        }
        ul {
            margin: 10px 0;
            padding: 0 20px;
        }
        footer {
            text-align: center;
            margin-top: 20px;
            font-size: 0.9em;
        }
    </style>
</head>
<body>
    <header>
        <h1>ATM Machine Program</h1>
    </header>
    <div class="container">
        <h2>Overview</h2>
        <p>
            This program is a console-based ATM system implemented in C. It simulates basic banking functionalities, 
            such as password changes, money transfers, balance updates, and account status checks. It also reads 
            and writes account information to a file (<code>acc.txt</code>) for persistence.
        </p>

  <h2>Features</h2>
        
  <ul>
            <li><strong>Login System</strong>: Users log in using an account number and password.</li>
            <li><strong>Menu Options</strong>: After logging in, users can:
                <ul>
                    <li>Change their password.</li>
                    <li>Transfer money to another account.</li>
                    <li>Deposit or withdraw cash.</li>
                    <li>Check their account balance (with a $1 fee applied).</li>
                    <li>Save changes and quit.</li>
                    <li>View account status for debugging purposes.</li>
                </ul>
            </li>
            <li><strong>Persistent Data Storage</strong>: Account information (account numbers, passwords, and balances) 
                is stored in a file (<code>acc.txt</code>) and is updated automatically when changes are made.</li>
        </ul>

  <h2>How It Works</h2>
        <h3>Data Handling</h3>
        <p>
            Account data is read from <code>acc.txt</code> on startup. The file contains data in a specific format 
            separated by hyphens (<code>-</code>).
        </p>
        <ul>
            <li>The first 10 entries are account IDs, the next 10 are passwords, and the last 10 are account balances.</li>
        </ul>
        <h3>Login Validation</h3>
        <p>Users are authenticated by comparing input credentials with the data loaded from the file.</p>
        <h3>Menu Options</h3>
        <p>
            Users are presented with a menu for available operations after successful login. Each operation modifies 
            the in-memory data, and changes are written back to the file when the user chooses to save and quit.
        </p>
        <h3>File Writing</h3>
        <p>
            The updated data is serialized back into the <code>acc.txt</code> file to maintain account consistency across sessions.
        </p>
        <h2>File Format: <code>acc.txt</code></h2>
        <p>The <code>acc.txt</code> file must follow this format:</p>
        <pre>
accountID1-accountID2-...-password1-password2-...-balance1-balance2-...
        </pre>
        <h3>Example</h3>
        <pre>
1001-1002-1003-...-1234-5678-9101-...-500-1000-1500-...
        </pre>
        <h2>How to Run</h2>
        <h3>Compile the Program</h3>
        <pre>
gcc atm.c -o atm
        </pre>
        <h3>Run the Program</h3>
        <pre>
./atm
        </pre>
        <h3>Initial Setup</h3>
        <p>
            Ensure <code>acc.txt</code> exists in the program's directory and follows the expected format.
        </p>
        <h2>Dependencies</h2>
        <ul>
            <li><strong>C Standard Library</strong>: Functions from <code>&lt;stdio.h&gt;</code>, <code>&lt;stdlib.h&gt;</code>, 
                <code>&lt;string.h&gt;</code> are used.</li>
            <li><strong>System Commands</strong>: The <code>system("cls")</code> and <code>system("clear")</code> commands 
                are used to clear the console (replace <code>cls</code> with <code>clear</code> for Linux).</li>
        </ul>
    </div>
    <footer>
        <p>Created for demonstration purposes.</p>
    </footer>
</body>
</html>
