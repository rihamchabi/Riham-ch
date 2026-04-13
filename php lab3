<?php
session_start();

require_once 'config.php';

$page = $_GET['page'] ?? 'login';

// دالة للتحقق من الدور
function requireRole($role) {
    if (!isset($_SESSION['user']) || $_SESSION['user']['role'] !== $role) {
        header("Location: index.php?page=login");
        exit;
    }
}

switch (true) {

    case ($page === 'login' || $page === 'logout'):
        require 'controllers/AuthController.php';
        break;

    case (str_starts_with($page, 'admin')):
        requireRole('admin');
        require 'controllers/AdminController.php';
        break;

    case (str_starts_with($page, 'professor')):
        requireRole('professor');
        require 'controllers/ProfessorController.php';
        break;

    case (str_starts_with($page, 'student')):
        requireRole('student');
        require 'controllers/StudentController.php';
        break;

    default:
        header("Location: index.php?page=login");
}
