import { BrowserRouter, Routes, Route, Link } from "react-router-dom";

function Register() {
  return (
    <div>
      <h2>Register</h2>
      <input placeholder="Name" />
      <input placeholder="Email" />
      <input type="password" placeholder="Password" />
      <button>Register</button>
    </div>
  );
}

function Login() {
  return (
    <div>
      <h2>Login</h2>
      <input type="email" placeholder="Email" />
      <input type="password" placeholder="Password" />
      <button>Login</button>
    </div>
  );
}

export default function App() {
  return (
    <BrowserRouter>
      <h1>Student Management System</h1>

      <Link to="/">Register</Link> |{" "}
      <Link to="/login">Login</Link> |{" "}
      <Link to="/contact">Contact</Link> |{" "}
      <Link to="/about">About</Link>

      <Routes>
        <Route path="/" element={<Register />} />
        <Route path="/login" element={<Login />} />
        <Route path="/contact" element={<h2>Contact us for help.</h2>} />
        <Route path="/about" element={<h2>This application helps manage student details.</h2>} />
      </Routes>
    </BrowserRouter>
  );
}